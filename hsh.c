#include "main.h"

/**
 *main - Functions that receives the commands entered by the user.
 *Return: Exit_succsess or exit failure.
 */

int main(void)
{
	char *line = NULL;
	char **argv = NULL, **envp = NULL;
	size_t line_size = 0;
	int status, i = 0;
	pid_t child_pid = 0;
	struct stat st;

	while (TRUE)
	{
		if (isatty(STDIN_FILENO) == 1)
			prompt();

		line_size = 0;
		getline(&line, &line_size, stdin);
		if (strcmp(line, "exit\n") == 0)
		{
			free(line);
			exit(0);
		}
		argv = tokenizer(line, DELIM_LINE);
		if (argv[0] == NULL)
			continue;
	
		envp = find_path(environ);
		
		child_pid = fork();
		
		if (child_pid == -1)
		{
			all_free(argv, envp, line);
			return (EXIT_FAILURE);
		}

		if (child_pid == 0)
			execve(argv[0], argv, environ);
		else
			wait(&status);

		all_free(argv, envp, line);
	}
	return (EXIT_SUCCESS);
}
