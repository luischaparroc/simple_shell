#include "holberton.h"

/**
 * shell_loop - Loop of shell
 * @datash: data relevant (av, input, args)
 *
 * Return: no return.
 */
void shell_loop(data_shell *datash)
{
	int loop;

	loop = 1;
	while (loop == 1)
	{
		write(STDIN_FILENO, "^-^ ", 4);
		datash->input = read_line();
		if (datash->input[0] != '\0')
		{
			datash->args = split_line(datash->input);
			loop = exec_line(datash);
			free(datash->input);
			free(datash->args);
		}
		else
		{
			loop = 0;
			free(datash->input);
		}
	}
}
