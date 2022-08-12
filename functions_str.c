#include "main.h"

/**
 *
 *
 *
 */
int _strlen(char *string)
{
	int len = 0;

	while (string[len])
		len++;
	return (len);
}

/**
 * _strcmp - compares two strings
 * @s1: string one
 * @s2: string two
 *
 * Return: 0 if equal or difference between s1 and s2
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	for (; s1[i] && s2[i]; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}

	return (s1[i] - s2[i]);
}

/**
 * *_strcpy - copy string
 *@dest: new string
 *@src: origin string
 *@*src: value string
 *@*dest: value new string
 *Return: dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0 ; src[i] != '\0' ; i++)
		dest[i] = src[i];
	if (src[i] == '\0')
		dest[i] = '\0';
	return (dest);
}

/**
 *
 *
 *
 */
int _strncmp(char *s1, char *s2, size_t n)
{
	size_t i = 0;

	for (; (s1[i] && s2[i]) && i < n; i++)
        {
                if (s1[i] != s2[i])
                        return (s1[i] - s2[i]);
        }

        return (s1[i] - s2[i]);
}
