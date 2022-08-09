#include <stdio.h>

/**
 * main - entry point
 * @ac: number of arguments
 * @av: arguments vector
 * Return: 0
 */
int main(int ac, char **av)
{
	size_t i = 0;

	for (i = 0; av[i] != NULL; i++)
	{
		printf("%s\n", av[i]);
	}

	return (0);
}
