#include "main.h"

/**
 *
 *
 *
 */
int _strlen(char *string)
{
	int len = 0;

	while (string[len])
		len++;

	return (len);
}

/**
 *
 *
 *
 */
char **tokenizer(char *line)
{
	char *delim = " \n\t", *token = NULL, *copy_line = NULL;
	char **argv = NULL;
	int count_token = 0, i = 0;

	copy_line = malloc(sizeof(char) * (_strlen(line) + 1));
	strcpy(copy_line, line);

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
		argv[i] = malloc(sizeof(char) * (_strlen(token) + 1));
		strcpy(argv[i], token);
		i++;
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;
	return (argv);
}
