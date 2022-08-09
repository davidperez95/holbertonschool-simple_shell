#include <string.h>
#include <stdio.h>

/**
 *main
 *
 *
 */

int main()
{
	char text[] = "Hola:Mundo:que:mas:pues";
	const char *separator = ":";
	char *token;

	token = strtok(text, separator);

	while (token != NULL)
	{
		printf("%s\n", token);

		token = strtok(NULL, separator);
	}

	return (0);
}
