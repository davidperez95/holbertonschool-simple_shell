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
	int status, i = 0, j = 0;
	pid_t child_pid;
	struct stat st;

	while (TRUE)
	{
		if (isatty(STDIN_FILENO) == 1)
		{
			if (write(STDOUT_FILENO, "$ ", 2) == EOF)
				exit(EXIT_FAILURE);
		}
		/**if (isatty(TRUE))
			prompt();
		if (!isatty(TRUE))
			break;*/
		/**characters_read =*/
		getline(&line, &line_size, stdin);
		argv = tokenizer(line, DELIM_LINE);
		if (argv[0] == NULL)
			continue;
		/*printf("%s", environ[0]);*/
		envp = find_path(environ);
		if (strcmp(argv[0], "exit") == 0)
		{
			for (i = 0; argv[i] != NULL; i++)
				free(argv[i]);
			if (argv[i] == NULL)
				free(argv[i]);

			free(argv);
			free(envp);
			free(line);

			exit(1);
		}
		/*child_pid = fork();
		
		if (child_pid == -1)
		{
			for (i = 0; argv[i] != NULL; i++)
				free(argv[i]);
			for (i = 0; envp[i] != NULL; i++)
				free(envp[i]);

				free(argv);
				free(envp);
				free(line);

			return (EXIT_FAILURE);
		}
		*/
		/*if (child_pid == 0)
		{
			execv(argv[0], argv);
		}
		wait(&status);*/

		for (i = 0; argv[i] != NULL; i++)
		{
			free(argv[i]);
		}
		if (argv[i])
			free(argv[i]);
		for (j = 0; envp[j] != NULL; j++)
			free(envp[j]);

		free(argv);
		free(envp);
		free(line);
		line = NULL;
		argv = NULL;
		envp = NULL;
	}
	return (EXIT_SUCCESS);
}
