#include "shell.h"

/**
 * main - A gateway to shell commands & prompt loop
 * Return: 0 on success
 */

int main(void)
{
	char *buffer = NULL;
	char **args;
	int val = 1;
	int loop_num = 0;

	while (val)
	{
		signal(SIGINT, ctrl_c_handler); /* this code stops ctrl ^C from exiting */

		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2); /* this code writes $ for shell */

		buffer = read_shell(); /* this code reads from command line */
		args = shell_line(buffer);
		val = shell_filter(args, environ); /* it tells if builtin */
		free(args);
		free(buffer);
		loop_num++;
	}
	return (0);
}

