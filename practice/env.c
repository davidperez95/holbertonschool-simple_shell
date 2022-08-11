#include <stdio.h>
#include <string.h>
#include "main.h"

extern char **environ;

int **find_path(char **environ)
{
	unsigned int i = 0;
	char *str_path = "PATH=";
	char *my_path = NULL;
	char **envp = NULL;

	while (environ[i] != NULL)
	{
		if (strncmp(environ[i], str_path, 5) == 0)
		{
			my_path = environ[i];
			break;
		}
		i++;
	}

	envp = tokenizer(my_path);

	return (env);
}
