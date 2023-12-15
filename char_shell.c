#include "shell.h"
#include <unistd.h>

/**
 * inter_shell - returns true if a shell is in interactive mode
 * @info: pointer to info_t structure
 *
 * Return: 1 if in interactive mode, 0 otherwise
 */
int inter_shell(ino_t *info)
{
	return (isatty(STDIN_FILENO) && info -> readfd <= 2);
}

/**
 * true_deli - checks if character is a delimeter
 * @q: the char to check
 * @deli: the delimeter string
 * Return: 1 if true, 0 if false
 */
int true_deli(char q, char *deli)
{
	while (*deli)
		if (*deli++ == q)
			return (1);
	return (0);
}

/**
 *alpha_shell - checks for alphabetic character
 *@q: The character to input
 *Return: 1 if q is alphabetic, 0 otherwise
 */

int alpha_shell(int q)
{
	if ((q >= 'a' && q <= 'z') || (q >= 'A' && q <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *str_int - converts a string to an integer
 *@s: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */

int str_int(char *s)
{
	int q, sim = 1, mas = 0, nom;
	unsigned int resultt = 0;

	for (q = 0;  s[q] != '\0' && mas != 2; q++)
	{
		if (s[q] == '-')
			sim *= -1;

		if (s[q] >= '0' && s[q] <= '9')
		{
			mas = 1;
			resultt *= 10;
			resultt += (s[q] - '0');
		}
		else if (mas == 1)
			mas = 2;
	}

	if (sim == -1)
		nom = -resultt;
	else
		nom = resultt;

	return (nom);
}
