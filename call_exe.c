#include "shell.h"
#include <unistd.h>
#include <stddef.h>

/**
 * exec_cmd - Executes a command.
 * @str: Vectorized array of user input representing
 * the command and its arguments.
 * @env: The environment variables.
 *
 * Return: 1 if successful, 0 on failure.
 */
int exec_cmd(char **str, char **env)
{
	pid_t pid, wpid;
	int nom = 0;
	char *newstr = malloc(8 * BUFFERSIZE), *path = malloc(8 * BUFFERSIZE);
	char *mas = malloc(sizeof(char) * BUFFERSIZE), *mel = NULL;

	if (input_check(str, env, newstr, path, mas))
		return (1);
	mas = _getenv(env, "PATH"), mel = _strcat("/", str[0]);
	pid = fork();
	if (pid == 0)
	{
		path = strtok(mas, ":");
		while (path)
		{
			newstr = _strcat(path, mel);
			if ((access(newstr, X_OK)) == 0)
			{
				free(mel);
				nom = execve(newstr, str, env);
				if (nom == -1)
					perror("hsh");
			}
			free(newstr), path = strtok(NULL, ":");
		}
		write(STDERR_FILENO, "hsh", _strlen("hsh") + 1);
		write(2, str[0], _strlen(str[0])), write(2, ": not found\n", 12);
		exit(EXIT_SUCCESS);
	}
	else if (pid < 0)
		perror("hsh");
	else
		do {
			wpid = waitpid(pid, &nom, WUNTRACED);
			if (wpid == -1)
				perror("hsh");
		} while (!WIFSIGNALED(nom) && !WIFEXITED(nom));
	free(mel), free(newstr), free(path), free(mas);
	return (1);
}

/**
 * input_check - This function checks and prepares input parameters.
 * @str: Double pointer to char, representing user input.
 * @env: Environmental variables.
 * @newstr: Char pointer for dynamic memory allocation.
 * @path: Char pointer for path manipulation.
 * @mas: Char pointer for environmental variable manipulation.
 *
 * Return: Integer indicating success (0) or failure (1).
 */

int input_check(char **str, char **env, char *newstr, char *path, char *mas)
{
	if ((check_input(str, env)) == 1)
	{
		return (1);
	}

	if (newstr == NULL || path == NULL || mas == NULL)
	{
		call_exit(NULL);
	}
	return (0);
}

/**
 * _getenv - Find the value of an environment variable.
 * @env: The environment variables.
 * @str: The pointer to the variable to find.
 *
 * Return: 1 on success, 0 on failure.
 */

char *_getenv(char **env, char *str)
{
	char *args = NULL, *copy = malloc(sizeof(char *) * BUFFERSIZE);
	char *path = malloc(sizeof(char *) * BUFFERSIZE);
	int nom = 0, len = 0, len2 = 0;
	int s = 0;

	while (*env)
	{
		path = _strdup(env[s]);

		args = strtok(path, "=");
		if (args != NULL && (_strcmp(args, str)) == 0)
		{
			path = _strdup(env[s]);

			while (args[++len])
				;
			len2 = len + 1;
			nom = _strlen(path) - len2;
			s = 0;
			while (s < nom)
			{
				copy[s] = path[len2];
				s++;
				len2++;
			}
			free(path);
			return (copy);
		}
		free(path);
		s++;
	}
	free(copy), free(path);
	return (NULL);
}

/**
 * find_env_var - Find the index of an environment variable.
 * @env: The environment variables.
 * @str: The pointer to the variable to find.
 *
 * Return: The index of the variable, or -1 if not found.
 */

int find_env_var(char **env, char *str)
{
	char *args = NULL;
	char *path = malloc(sizeof(char) * BUFFERSIZE);
	int s = 0;

	while (*env)
	{
		path = _strdup(env[s]);
		args = strtok(path, "=");

		if (args != NULL && (_strcmp(args, str)) == 0)
		{
			free(path);
			return (s);
		}
		free(path);
		s++;
	}
	return (0);
}

/**
 * check_input - Check if the input is already a path.
 * @env: The environment variables.
 * @str: The vectorized array of input.
 *
 * Return: 1 on success, 0 on failure.
 */

int check_input(char **str, char **env)
{
	pid_t pid, wpid;
	int nom = 0, s = 0;
	char *lane = "/";
	char *lusi = NULL;

	lusi = _strdup(str[0]);
	if ((access(str[0], R_OK | X_OK)) == 0)
	{
		pid = fork();
		if (pid == 0)
		{
			nom = execve(str[0], str, env);
			if (nom == -1)
			{
				perror("hsh");
			}
			exit(EXIT_SUCCESS);
		} else if (pid < 0)
			perror("hsh");
		else
			do {
				wpid = waitpid(pid, &nom, WUNTRACED);
				if (wpid == -1)
					perror("hsh");
			} while (!WIFSIGNALED(nom) && !WIFEXITED(nom));
		free(lusi);
		return (1);
	}
	else if (lusi != NULL)
	{
		for (s = 0; lusi[s] != '\0'; s++)
			if (lusi[s] == lane[0])
			{
				errno = ENOENT;
				perror("hsh"), free(lusi);
				return (1);
			}
	}
	free(lusi);
	return (0);
}
