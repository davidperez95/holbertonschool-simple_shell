#include "main.h"

extern char **environ;
/**
 *main - Functions that receives the commands entered by the user.
 *@line: User-entered command
 *@argv: The different commands entered by the user.
 *@envp: Enviironments variables.
 *Return: Exit_succsess or exit failure.
 */

int main(void)
{
	char *line = NULL;
	char **argv = NULL, **envp = NULL;
	size_t line_size = 0;
	int status;/**characters_read = 0;*/
	pid_t child_pid;

	while (TRUE)
	{
		if (isatty(TRUE))
			prompt();
		if (!isatty(TRUE))
			break;
		/**characters_read =*/
		getline(&line, &line_size, stdin);
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
