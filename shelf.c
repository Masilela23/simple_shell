#include "shell.h"

/**
 * shell_filter - Filters built-in commands and
 * sends them to the appropriate function.
 * @commands: Double pointer representing the command line.
 * @env: Environment variables.
 *
 * Return: Return value of the exec_cmd function.
 */

int shell_filter(char **commands, char **env)
{
	int opt = 0;
	char *builtin[7] = {"exit", "cd", "env", "holberton", "unsetenv",
			    "setenv", NULL};

	if (commands[0] == NULL) /* If no args at all, continue */
		return (1);
	while (builtin[opt] != NULL)
	{
		if (_strcmp(builtin[opt], commands[0]) == 0)
			break;
		opt++;
	}
	switch (opt)
	{
	case 0: /* Exit */
		if (commands[1] == NULL) /* Only exit is typed */
			call_exit(commands);
		else
			call_exit_status(commands); /* Is 2nd arg after exit */
		break;
	case 1:
		call_cd(commands); /* cd is typed */
		break;
	case 2:
		call_env(env); /* env is typed */
		break;
	case 3:
		call_unsetenv(env, commands);
		break;
	case 4:
		call_setenv(env, commands);
		break;
	default:
		return (exec_cmd(commands, env)); /* No builtin found */
	}
	return (opt);
}

/**
 * ctrl_c_handler - Handles the interrupt signal (Ctrl+C).
 * @sig_num: Integer representing the signal number.
 *
 * Return: void.
 */

void ctrl_c_handler(int sig_num __attribute__((unused)))
{
	signal(SIGINT, ctrl_c_handler);
	write(STDOUT_FILENO, "\n$ ", 3);
}

/**
 * shell_line - Uses strtok to split a line into arguments
 * and stores them in an array.
 * @line: Char pointer representing the input line.
 *
 * Return: Double char pointer containing the arguments.
 */


char **shell_line(char *line)
{
	int buffer_size = BUFFERSIZE;
	int location = 0;
	char **tokens = NULL;
	char *token = NULL;

	tokens = malloc(sizeof(char *) * buffer_size);
	if (!tokens)
	{
		perror("hsh");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, DELIMINATOR);

	while (token != NULL)
	{
		tokens[location] = token;
		token = strtok(NULL, DELIMINATOR);
		location++;
	}
		if (location >= buffer_size)
		{
			buffer_size += BUFFERSIZE;
			tokens = _realloc(tokens, BUFFERSIZE,
					  buffer_size * sizeof(char *));

			if (!tokens)
			{
				{
					perror("hsh: allocation error\n");
					exit(EXIT_FAILURE);
				}
			}
			token = strtok(NULL, DELIMINATOR);
		}
	tokens[location] = NULL;
	return (tokens);
}

/**
 * read_shell - Reads arguments using getline.
 *
 * Return: void.
 */

char *read_shell(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	int s = 0;

	s = getline(&line, &bufsize, stdin);

	if (s == EOF)
	{
		if ((isatty(STDIN_FILENO)) == 1)
			write(1, "\n", 1);
		exit(0);
	}
	return (line);
}

