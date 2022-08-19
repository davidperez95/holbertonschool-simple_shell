#include "main.h"

/**
 * get_command - Redirects to built funtions
 * @command: Command received
 * Return: Pointer to the funtions
 */
void (*get_command(char *command))(void)
{
	int i = 0;

	built_t functions[] = {
	{"env\n", env_func},
	{"help\n", help_func},
	{NULL, NULL}
	};

	for (; functions[i].command != NULL; i++)
	{
		if (_strcmp(functions[i].command, command) == 0)
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

/**
 * help_func - Print some options to execute
 * Return: void
 */
void help_func(void)
{
	_printf("env:  Enviroment Variables\n");
	_printf("ls:   Files and directories\n");
	_printf("pwd:  Working directory\n");
	_printf("exit: Exit shell\n");
}
