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

/**
 * _strlen - this function will return
 * the length of a string
 * @str: arg string
 *
 * Return: String length
 */

int _strlen(char *str)
{
	int length = 0;

	while (str[length] != '\0')
	{
		length++;
	}
		return (length);
}

/**
 * _strdup - this function is the copy of
 * the string given as a parameter.
 * @str: unsigned int
 *
 * Return: char pointer
 */

char *_strdup(const char *str)
{
	unsigned int count1, count2;
	char *strCopy;

	count1 = 0;
	count2 = 0;

	if (str == NULL)
	{
		return (0);
	}

	while (str[count1] != '\0')
	{
		count1++;
	}

	strCopy = malloc(sizeof(char) * (count1 + 1));
	if (strCopy == NULL)
	{
		return (NULL);
	}

	while (count2 < count1)
	{
		strCopy[count2] = str[count2];
		count2++;
	}

	strCopy[count2] = '\0';

	return (strCopy);
}
/**
 * _strcmp - this function compares strings
 * @str1: arg char
 * @str2: arg char
 *
 * Return: string to stdout
 */


int _strcmp(char *str1, char *str2)
{

	int inx;

	for (inx = 0; str1[inx] != '\0' || str2[inx] != '\0'; inx++)
	{
		if (str1[inx] != str2[inx])
		{
			return (str1[inx] - str2[inx]);
		}
	}
		return (0);
}
/**
 * _atoi - this function converts a string to an integer.
 * @s: input string
 * Return: integer
 */

int _atoi(char *s)
{
	int sig = 1, m = 0;
	unsigned int unsig = 0;

	while (!(s[m] <= '9' && s[m] >= '0') && s[m] != '\0')
	{
		if (s[m] == '-')
			sig *= -1;
		m++;
	}
	while (s[m] <= '9' && (s[m] >= '0' && s[m] != '\0'))
	{
		unsig = (unsig * 10) + (s[m] - '0');
		m++;
	}
	unsig *= sig;
	return (unsig);
}
/**
 * _strcat - this function adds two strings together
 * @s1: First string to add
 * @s2: Second string to add
 * Return: Always temp
 */

char *_strcat(char *s1, char *s2)
{
	int i, j, k, size;
	char *temp;

	i = 0;
	j = 0;
	k = 0;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;

	size = i + j + 1;
	temp = malloc(size * sizeof(char));
	if (temp == NULL)
		return (NULL);

	j = 0;

	while (k < size)
	{
		if (k < i)
		{
			temp[k] = s1[k];
		}
		else
		{
			temp[k] = s2[j];
			j++;
		}
		k++;
	}

	temp[k - 1] = '\0';
	return (temp);
}
