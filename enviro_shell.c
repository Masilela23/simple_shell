#include "shell.h"
#include <unistd.h>
#include <stddef.h>

/**
 * printenv_ - prints the current environment
 * @info: Structure containing potential arguments. Maintains a
 * constant function prototype
 * Return: Always 0
 */
int printenv_(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * recenv - gets the value of an environ variable
 * @info: structure with possible arguments. Maintains a
 * constant function prototype
 * @name: environ var name
 *
 * Return: variable value
 */
char *recenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *q;

	while (node)
	{
		q = starts_with(node->str, name);
		if (q && *q)
			return (q);
		node = node->next;
	}
	return (NULL);
}

/**
 * new_env - handles the initialization and modification of an environment
 *
 * @info: structure with possible arguments. Maintains a
 * constant function prototype.
 *  Return: Always 0
 */
int new_env(info_t *info)
{
	if (info->argc != 3)
	{
		in_puts("Incorrect number of arguements\n");
		return (1);
	}
	if (setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * edit_env - Remove an environment variable
 * @info: Structure with possible arguments. Maintains a
 * constant function prototype.
 *  Return: Always 0
 */
int edit_env(info_t *info)
{
	int c;

	if (info->argc == 1)
	{
		puts("Too few arguements.\n");
		return (1);
	}
	for (c = 1; c <= info->argc; c++)
		unsetenv(info, info->argv[c]);

	return (0);
}

/**
 * enviro_list - lists variables in the environment
 * @info: Possible arguments. Maintains a
 * constant function prototype
 * Return: Always 0
 */
int enviro_list(info_t *info)
{
	list_t *node = NULL;
	size_t v;

	for (v = 0; environ[v]; v++)
		add_node_end(&node, environ[v], 0);
	info->env = node;
	return (0);
}
