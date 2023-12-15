#include "shell.h"
#include <stdio.h>
#include <unistd.h>

/**
 * ret_env - retrieves a copy of variables as a string array
 * @info: Possible arguments. Maintains
 *          constant function prototype.
 * Return: Always 0
 */
char **ret_env(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}

/**
 * edit_env - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: 1 on delete, 0 otherwise
 * @var: the string env var property
 */
int edit_env(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t v = 0;
	char *k;

	if (!node || !var)
		return (0);

	while (node)
	{
		k = starts_with(node->str, var);
		if (k && *k == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), v);
			v = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		v++;
	}
	return (info->env_changed);
}

/**
 * new_env - handles the initialization and modification of an environment
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @var: the string env var property
 * @value: the string env var value
 *  Return: Always 0
 */
int new_env(info_t *info, char *var, char *value)
{
	char *bufr = NULL;
	list_t *node;
	char *k;

	if (!var || !value)
		return (0);

	bufr = malloc(_strlen(var) + _strlen(value) + 2);
	if (!bufr)
		return (1);
	_strcpy(bufr, var);
	_strcat(bufr, "=");
	_strcat(bufr, value);
	node = info->env;
	while (node)
	{
		k = starts_with(node->str, var);
		if (k && *k == '=')
		{
			free(node->str);
			node->str = bufr;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), bufr, 0);
	free(bufr);
	info->env_changed = 1;
	return (0);
}
