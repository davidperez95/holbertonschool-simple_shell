#include "main.h"

/**
 *main - Functions that receives the commands entered by the user.
 *Return: Exit_succsess or exit failure.
 */

int main(void)
{
	char *line = NULL, **argv = NULL, **envp = NULL;
	size_t line_size = 0;
	ssize_t command = 0;
	int status = 0;
	pid_t child_pid = 0;
	void (*function)(void) = NULL;

	while (TRUE)
	{
		if (isatty(STDIN_FILENO) == 1)
			prompt();
		line_size = 0, 
		command = getline(&line, &line_size, stdin);
		if (command == EOF)
		{
			free(line);
			break;
		}

		if (strcmp(line, "exit\n") == 0)
		{
			free(line);
			return (WEXITSTATUS(status));
		}

		function = get_command(line);
		if (function != NULL)
		{
			free(line);
			function();
			continue;
		}

		argv = tokenizer(line, DELIM_LINE);
		if (argv == NULL)
		{
			free(line);
			continue;
		}

		envp = find_path(environ);
		child_pid = fork();

		if (child_pid == -1)
		{
			all_free(argv, envp, line);
			return (EXIT_FAILURE);
		}
		_check_argv(argv[0]);
		if (child_pid == 0)
			execve(argv[0], argv, environ);
		else
			wait(&status);
		all_free(argv, envp, line);
	}
	return (WEXITSTATUS(status));
}
