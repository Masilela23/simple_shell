#include "shell.h"
#include <string.h>

/**
 * plus_node - adds a node to the start of the list
 * @head: address of pointer to head node
 * @str: str field of node
 * @num: node index used by history
 *
 * Return: size of list
 */
list_t *plus_node(list_t **head, const char *str, int num)
{
	list_t *new_node;

	if (!head)
		return (NULL);
	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);
	_memset((void *)new_node, 0, sizeof(list_t));
	new_node->num = num;
	if (str)
	{
		new_node->str = _strdup(str);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}
	new_node->next = *head;
	*head = new_node;
	return (new_node);
}

/**
 * insert_at_end - adds a node to the end of the list
 * @head: address of pointer to head node
 * @str: str field of node
 * @num: node index used by history
 *
 * Return: size of list
 */
list_t *insert_at_end(list_t **head, const char *str, int num)
{
	list_t *new_list_node, *node;

	if (!head)
		return (NULL);

	node = *head;
	new_list_node = malloc(sizeof(list_t));
	if (!new_list_node)
		return (NULL);
	_memset((void *)new_list_node, 0, sizeof(list_t));
	new_list_node->num = num;
	if (str)
	{
		new_list_node->str = _strdup(str);
		if (!new_list_node->str)
		{
			free(new_list_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_list_node;
	}
	else
		*head = new_list_node;
	return (new_list_node);
}

/**
 * prnt_str_list - prints only the ‘str’ element of a list_t linked list
 * @h: pointer to first node in
 *
 * Return: size of list
 */
size_t prnt_str_list(const list_t *h)
{
	size_t v = 0;

	while (h)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		v++;
	}
	return (v);
}
