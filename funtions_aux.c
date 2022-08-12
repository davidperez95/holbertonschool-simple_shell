#include "main.h"

extern char **environ;

/**
 *prompt - Printed character that prompts the user to enter a command.
 *
 *Return: 0 if it receives a character
 */
int prompt(void)
{
	char *prompt = "$ ";

	write(STDOUT_FILENO, prompt, _strlen(prompt));
	return (0);
}

/**
 *tokenizer - Functions that separates the command by delimiters
 *@line: Command inserted by user
 *@delim: Delimiter
 *Return: The arguments that make up the commands
 */
char **tokenizer(char *line, char *delim)
{
	char *token = NULL, *copy_line = NULL;
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
	if (!argv)
		return (NULL);
	token = strtok(copy_line, delim);
	while (token != NULL)
	{
		argv[i] = malloc(sizeof(char) * (_strlen(token) + 1));
		if (!argv[i])
		{
			free(argv[i]);
			free(argv);
			return (NULL);
		}
		strcpy(argv[i], token);
		i++;
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;
	return (argv);
}

/**
 *find_path - Functions that finds the environment varibles in the path
 *@environ: Environment varibles in the path
 *Return: Environment variables
 */
char **find_path(char **environ)
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

	envp = tokenizer(my_path, DELIM_PATH);

	return (envp);
}
