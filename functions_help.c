#include "main.h"

/**
 *
 *
 *
 */
char *_check_argv(char *argv)
{
	char *concat = NULL;
	char *str = "/bin/";
	int i = 0, j = 0;

	
	if (argv[0] != '/')
	{
		concat = malloc(sizeof(char) * (_strlen(str) + _strlen(argv) + 1));
		for (i = 0; str[i] != '\0'; i++)
			concat[i] = str[i];

		for (j = 0; argv[j] != '\0'; i++, j++)
			concat[i] = argv[j];

		concat[i] = '\0';

		argv = concat;
		free(concat);
		return (argv);
	}

	return (argv);
}
