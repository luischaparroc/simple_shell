#include "holberton.h"

/**
 * shell_loop - Loop of shell
 *
 * Return: no return.
 */
void shell_loop(void)
{
	char *input;
	char **args;
	int status;

	status = 1;
	while (status)
	{
		write(STDOUT_FILENO, "^-^ ", 4);
		input = read_line();
		if (input[0] != '\0')
		{
			args = split_line(input);
			status = exec_line(args, input);
			free(input);
			free(args);
		}
		else
		{
			write(STDOUT_FILENO, "\n", 1);
			status = 0;
		}
	}
}
