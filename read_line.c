#include "holberton.h"

/**
 * read_line - reads the input string.
 *
 * Return: input string
 */
char *read_line(void)
{
	char *input = NULL;
	ssize_t bufsize = 0;

	get_line(&input, &bufsize, stdin);
	return (input);
}
