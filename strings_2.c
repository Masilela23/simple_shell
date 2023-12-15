#include "shell.h"

/**
 *  _isdigit - this function finds if char is a digit or not
 *  @str: Character passed in
 *
 *  Return: 1 for success, 0 if not
 */

int _isdigit(char str)
{
	if (str >= '0' && str <= '9')
	{
		return (1); /* Success */
	}
	return (0);
}
/**
 *  _exit_atoi - this function atoi for exit status
 *  @str: String passed through
 *
 *  Return: Exit int or -1 on failure
 */

int _exit_atoi(char *str)
{
	int result = 0, index = 0, int_max = 2147483647;

	/* Is negative */
	if (str[index] == '-')
	{
		return (1);
	}

	while (str[index] != '\0')
	{
		if (_isdigit(str[index]) == 1)
		{
			result = result * 10 + str[index] - '0';
		}
		else
		{
			return (1);
		}
		index++;
	}

	if (result > int_max)
	{
		return (1);
	}
	else
		return (result);
}
/**
 * _strcpy -this function prints a string
 * @dest: Destination
 *
 * @src: Source
 * Return: Always dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}

int _getchar(void)
{
	char buffer[BUFFERSIZE];
	char *buff = buffer;
	int index = 0;

	if (index == 0)
	{
		index = read(0, buffer, 1);
	}
	if (index-- >= 0)
	{
		return (*buff++);
	}
	return (EOF);
}
/**
 * word_counter - Counts words
 *
 * @str: char pointer
 *
 * Return: Integer
 */


int word_counter(char *str)
{
	int count1, count2 = 0;

	for (count1 = 0; str[count1] != '\0'; count1++)
	{
		if (str[count1] != ' ' && (str[count1 + 1] == ' ' ||
					   str[count1 + 1] == '\0'))
		{
			count2++;
		}
	}
	return (count1);
}
