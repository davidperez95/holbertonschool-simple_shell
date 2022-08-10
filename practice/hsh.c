#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define TRUE 1

int _strlen(char *string)
{
	int len = 0;

	while (string[len])
		len++;
	return (len);
}

int prompt(void)
{
	char *prompt = "$ ";
	write(STDOUT_FILENO, prompt, _strlen(prompt));
	return (0);
}

int main(void)
{
	char *line = NULL;
	size_t line_size = 0;
	int status;
	int characters_read = 0;
	pid_t child_pid;
	char *argv[] = {NULL};
	char *envp[] = {NULL};

	while (TRUE)
	{
		/* chequeamos si es interactivo */
		if (isatty(TRUE))
		/* si es interactivo llamamos a la función prompt */
			prompt();
		if (!isatty(TRUE))
			break;
		/* leemos los caracteres de entrada */
		characters_read = getline(&line, &line_size, stdin);
		/* asignamos el comando a la posición 0 de argv */
		argv[0] = line;
		/* creamos el proceso hijo */
		child_pid = fork();
		if (child_pid == -1)
			return (EXIT_FAILURE);
		if (child_pid == 0)
		{
			/* si el proceso hijo se crea, se ejecuta el comando pasado a argv[0] */
			/* IMPORTANTE */
			/* en el espacio de NULL hay que poner el camino del PATH para que se
			 * encuentre el comando, usando extenr char **environ */
			if (execve(argv[0], argv, NULL) == -1)
			       perror("error");
		}
		else
		{
			/* el proceso padre espera */
			wait(&status);
		}
		/* liberamos la linea creada con getline */	
		free(line);
	}
	return (EXIT_SUCCESS);
}
