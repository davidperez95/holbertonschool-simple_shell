#include "main.h"

/**
 * get_command - Redirects to built funtions
 * @command: Command received
 * Return: Pointer to the funtions
 */
void (*get_command(const char *command))(void)
{
	int i = 0;

	built_t functions[] = {
	{"env\n", env_func},
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
 * Return: void
 */
void env_func(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
	_printf("%s\n", environ[i]);
		i++;
	}
}
