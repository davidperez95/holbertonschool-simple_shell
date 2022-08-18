#include "main.h"

/**
 * _check_argv - check of argv
 * @command: Command recived
 * @envp: PATH
 * Return: concat, NULL
 */
char *_check_argv(char *command, char **envp)
{
	char *concat = NULL;
	struct stat st;
	int i = 0, len_command = 0, len_envp = 0;

	if (stat(command, &st) == 0)
		return (command);

	for (i = 1; envp && envp[i]; i++)
	{
		len_command = _strlen(command);
		len_envp = _strlen(envp[i]);

		concat = malloc(sizeof(char) * (len_command + len_envp) + 2);

		if (concat == NULL)
			return (NULL);

		_strcpy(concat, envp[i]);
		_strcat(concat, "/");
		_strcat(concat, command);

		if (stat(concat, &st) == 0)
		{
			free(command);
			return (concat);
		}
		free(concat);
	}
	_printf("./hsh: 1: %s: not found\n", command);
	free(command);
	return (NULL);
}

/**
 * execute_child - creates a child and executes it
 * @argv: list of arguments to execute
 * @status: status of father
 * Return: status.
 */
int execute_child(char **argv, int status)
{
	pid_t child_pid = 0;

	child_pid = fork();
	if (child_pid == -1)
		return (WEXITSTATUS(status));
	if (child_pid == 0)
		execve(argv[0], argv, environ);
	else
		wait(&status);

	return (status);
}

/**
 * read_line - reads the input line
 * @line: buffer to store line
 * @line_size: number of bytes of line
 * Return: pointer to buffer line
 */
char *read_line(char *line, size_t line_size)
{
	ssize_t command = 0;

	command = getline(&line, &line_size, stdin);
	if (command == EOF)
	{
		free(line);
		exit(0);
	}

	return (line);
}
