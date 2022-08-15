#include "main.h"

/**
 * get_command - Redirects to built funtions
 * @command: Command received
 * Return: Pointer to the funtions
 */
int (*get_comman(char *command))
{
	int i = 0;

	built_t functions[] = {
	{"env", env_func},
	{NULL, NULL}
	};

	for (; functions[i].command != NULL; i++)
	{
	if (*(functions[i].command) == *command)
		break;
	}
	return (functions[i].function_built);
}

/**
 * env_func - Print all the enviroment
 * Return: 0
 */
int env_func(char *)
{
	int i = 0;

	while (environ[i] != NULL)
	{
	printf("%s\n", environ[i]);
		i++;
	}
	return (0);
}
