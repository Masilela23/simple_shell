#include "shell.h"

/**
 * _realloc - Reallocates space for a memory block.
 * @ptr: Pointer to the memory block to be reallocated.
 * @old_size: Old size of the memory block.
 * @new_size: New size of the memory block.
 *
 * Return: Pointer to the reallocated memory block, or NULL on failure.
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_pointer;
	unsigned int m = 0;

	if (old_size == new_size)
		return (ptr);

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	new_pointer = malloc(new_size);

	if (new_pointer == NULL)
		return (NULL);

	while (m < old_size)
	{
		*((char *)new_pointer + m) = *((char *)ptr + m);
		m++;
	}
	free(ptr);
	return (new_pointer);
}

