#include "main.h"

/**
 *
 *
 *
 */
char *_check_argv(char *argv)
{
	int i;
	char *complement = "/bin/";
  
	while (argv[i] != '\0')
		i++;
	if (argv[0] != '/')
		_strcat(complement, argv);
	argv = complement;
	return (argv);
}
