#include "main.h"
/**
 * _printf - Entru point.
 * Description: Funtion that prints string format.
 *
 * @format: arguments function
 * Return: print_len
 */

int _printf(const char *format, ...)
{
	int i = 0, bf_count = 0;
	char *buffer = NULL;
	void (*op_functions)(char *, va_list, int *);
	va_list ap;

	va_start(ap, format), buffer = malloc(sizeof(char) * 2048);
	if (!format || !buffer || (format[i] == '%' && !format[i + 1]))
		return (-1);
	if (!format[i])
		return (0);
	for (; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				continue;

			op_functions = get_op_functions(format[i + 1]);
			if (op_functions == NULL)
			{
				buffer[bf_count] = format[i];

				if (format[i + 1] != '%')
				{
					buffer[bf_count + 1] = format[i + 1];
					bf_count += 2;
				}
				else
					bf_count++;
			}
			else
				op_functions(buffer, ap, &bf_count);
			i++;
			continue;
		}
		buffer[bf_count] = format[i];
		bf_count++;
	}
	va_end(ap), write(1, buffer, bf_count), free(buffer);
	return (bf_count);
}

/**
 * get_op_functions - Function that returns an option.
 *
 * @c: compare a character for function.
 *
 * Return: if c = NULL returns a NULL, if c = char returns option.
 *
 */


void (*get_op_functions(char c))(char *, va_list, int *)
{
	int i = 0;
	functions ops[] = {
			{"s", op_string},
			{NULL, NULL}
	};

	for (; ops[i].op != NULL; i++)
	{
		if (*ops[i].op == c)
			return (ops[i].f);
	}

	return (NULL);
}

/**
 * op_string - Function entry point.
 *
 * Description: Function that return a string.
 *
 * @buffer: Space for memory.
 * @ap: Arguments for funtion.
 * @bf_count: iterating pointer.
 */

void op_string(char *buffer, va_list ap, int *bf_count)
{
	int i;
	char *ch = NULL;

	ch = va_arg(ap, char *);

	if (ch == NULL)
		ch = "(null)";

	for (i = 0; ch[i] != '\0'; i++)
	{
		buffer[*bf_count] = ch[i];
		(*bf_count)++;
	}
}
