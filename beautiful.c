#include "shell.h"
#include <stdio.h>
#include <unistd.h>

/**
 * main - sum
 *
 * Return: 0
 */

int main(void)
{
	int s = 10;
	int m = 5;
	int sum = s + m;
	pid_t pid;

	pid = getpid();

	printf("sum is %d\n", sum);
	printf("pid is %u\n", pid);

	return (0);
}
