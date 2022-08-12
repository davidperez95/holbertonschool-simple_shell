#include "main.h"

extern char **environ; 

int prompt(void)
{
	char *prompt = "$ ";
	write(STDOUT_FILENO, prompt, _strlen(prompt));
	return (0);
}

int main(void)
{
	char *line = NULL, **argv = NULL, **envp = NULL;
	size_t line_size = 0;
	int status, characters_read = 0;
	pid_t child_pid;

	while (TRUE)
	{
		if (isatty(TRUE))
			prompt();
		if (!isatty(TRUE))
			break;
		characters_read = getline(&line, &line_size, stdin);
		argv = tokenizer(line, DELIM_LINE);
		if (argv[0] == NULL)
			continue;
		envp = find_path(environ);
		if (strcmp(argv[0], "exit") == 0)
		{
			free(line), free(argv), free(envp);
			exit(1);
		}
		child_pid = fork();
		if (child_pid == -1)
		{
			free(line), free(argv), free(envp);
			return (EXIT_FAILURE);
		}
		if (child_pid == 0)
		{
			if (execve(argv[0], argv, envp) == -1)
			       perror("error");
		}
		else
		{
			wait(&status);
		}
		free(line), free(argv), free(envp);
	}
	return (EXIT_SUCCESS);
}
