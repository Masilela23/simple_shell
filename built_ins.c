#include "shell.h"

/**
 * call_exit - Exit the shell.
 * @args: Char pointer representing the command arguments.
 *
 * Return: Integer.
 */

void call_exit(char **args)
{
	free(*args);
	free(args);
	exit(EXIT_SUCCESS);
}
/**
 * call_exit_status - Exit the program with a specified status.
 * @args: A double pointer representing the command arguments.
 *
 * Return: void
 */

int call_exit_status(char **args)
{
	int sim;

	sim = _exit_atoi(args[1]);

	if (sim == -1)
	{
		perror("hsh");
		return (0);
	}
	else
	{
		exit(sim);
	}
}
/**
 * call_cd - Change the current working directory.
 * @args: Char pointer representing the command arguments.
 *
 * Return: Integer.
 */

int call_cd(char **args)
{
	char *target_dir = NULL, *home = NULL;

	home = _getenv(environ, "HOME");

	if (args[1])
	{
		/* for cd ~ go home */
		if (_strcmp(args[1], "~"))
		{
			target_dir = home;
		}
		/* target_dir to the value of the OLDPWD environment variable.*/
		else if (_strcmp(args[1], "-"))
			target_dir = _getenv(environ, "OLDPWD");
		else
			target_dir = args[1];
	}
	else
		target_dir = home;

	if (target_dir == home)
		chdir(target_dir);

	/* F_OK tests if there */
	/* R_OK grants read permissions */
	else if (access(target_dir, F_OK | R_OK) == 0)
		chdir(target_dir);
	else
		perror("hsh");
	/*setenv("OLDPWD", _getenv(environ, "PWD"), 1);*/
	/*setenv("PWD", getcwd(prevDir, sizeof(prevDir)), 1);*/
	return (0);
}

