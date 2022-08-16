#include "main.h"

/**
 * get_command - Redirects to built funtions
 * @command: Command received
 * Return: Pointer to the funtions
 */
void (*get_command(const char *command))
{
	int i = 0;

	built_t functions[] = {
	{"env\n", env_func},
	{"exit\n", exit_func},
	{NULL, NULL}
	};

	for (; functions[i].command != NULL; i++)
	{
		if (strcmp(functions[i].command, command) == 0)
			break;
	}
	return (functions[i].function_built);
}

/**
 * env_func - Print all the enviroment
 *
 */
void env_func(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
	printf("%s\n", environ[i]);
		i++;
	}
}

/**
 * exit_func - exit to the shell
 *
 */
void exit_func(void)
{
	exit(0);
}
