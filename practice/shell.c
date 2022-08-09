#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int _strlen(char *string)
{
	int len = 0;

	while (string[len])
		len++;

	return (len);
}

int main()
{
	char *prompt = "$ ";
	char *line = NULL;
	size_t line_size = 0;
	int characters_read = 0;

	while (1)
	{
		write(STDOUT_FILENO, prompt, _strlen(prompt));

		characters_read = getline(&line, &line_size, stdin);

		write(STDOUT_FILENO, line, characters_read);
	}

	return (0);
}
