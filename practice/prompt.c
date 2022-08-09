#include <stdio.h>
#include <stdlib.h>

int main(int ac __attribute__((__unused__)), char **av __attribute__((__unused__)))
{
	char *buffer = NULL;
	size_t bufsize = BUFSIZ;
	size_t nchars = 0;

	buffer = (char *)malloc(sizeof(char) * bufsize);
	if (!buffer)
		exit(1);

	printf("$ ");
	nchars = getline(&buffer, &bufsize, stdin);
	printf("%ld\n", nchars);
	printf("%s", buffer);

	free(buffer);

	return (0);
}
