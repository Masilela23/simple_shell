#include "shell.h"

/**
 * _putchar - this function writes
 * the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - this function will  print a string
 * @str: args
 *
 * Return: string to stdout
 */

void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}
	_putchar('\n');
}
