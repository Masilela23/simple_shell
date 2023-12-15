#include "shell.h"

/**
 *  call_exit – this function exits shell
 *  @args: it passes in char pointer
 *  Return: Int
 */
void call_exit(char **args)
{
	free(*args);
	free(args);
	exit(EXIT_SUCCESS);
}
/**
 *  call_exit_status – this function exits with a status
 *  @args: A double pointer
 *  Return: void
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
 *  call_cd – this function will change directory
 *  @args: it passes in char pointer
 *  Return: Int
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

