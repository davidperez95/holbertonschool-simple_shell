#include <string.h>

extern char **environ;

int main(int ac, char **av, char **env)
{
	unsigned int i;

	for (i = 0; environ[i] != '\0' | env[i] != '\0'; i++)
	{
		printf("%s\n", env[i]);
		printf("%d\n", env[i]);
		printf("%s\n", environ[i]);
		printf("%d\n", environ[i]);
	}
	return (0);
}
