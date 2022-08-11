#include "main.h"

/**
 *
 *
 *
 */
int **_strtok(char *line, char *argv[])
{
	char *token;
	int count_token = 0, i;
	char *copy_line = strcpy(line, copy_line);

	token = strtok(line, delim);
	while (token != NULL)
	{
		token = strtok(NULL, delim); 
		count_token++;
	}
	count_token++;

	argv = malloc(sizeof(char *) * count_token);

	token = strtok(copy_line, delim);
	while (token != NULL)
	{
		argv[i] = malloc (sizeof(char) * strlen(token));
		strcpy(argv[i], token);
		i++;
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;
	return (argv[i])
}
