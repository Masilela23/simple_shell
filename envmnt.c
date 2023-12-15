#include "shell.h"

/**
 * call_env - Built-in function to display the environment.
 * @env: Double pointer to char representing the environment.
 *
 * Return: Integer.
 */

int call_env(char **env)
{
	int s = 0;
	int len = 0;
	char *lusi = malloc(8192);

	while (env[s] != NULL)
	{
		len = _strlen(env[s]);
		lusi = _strdup(env[s]);

		write(STDOUT_FILENO, lusi, len + 1);
		write(1, "\n", 1);
		free(lusi);
		s++;
	}
	return (1);
}

