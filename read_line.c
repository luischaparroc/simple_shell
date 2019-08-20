#include "holberton.h"

/**
 * read_line - reads the input string.
 *
 * Return: input string
 */
char *read_line(void)
{
	char *input = NULL;
	size_t bufsize = 0;

	getline(&input, &bufsize, stdin);

	return (input);
}
