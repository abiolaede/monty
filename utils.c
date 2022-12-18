#include "monty.h"

int isonlydigit(char *s);

/**
 * isonlydigit - checks if a string contains only digits
 * @s: string to be checked
 * Description: checks if a string contains only digit
 * Return: 1 if string contains only didgit
 *         0 if string has at lest one non-digit character
 */
int isonlydigit(char *s)
{
	if (s == NULL)
		return (0);
	if (s[0] == '\0')
		return (0);
	while (*s != '\0')
	{
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	return (1);
}
