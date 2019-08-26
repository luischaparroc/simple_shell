#include "holberton.h"

/**
 * is_a_comment - defines if an input string is a comment
 *
 * @input: input string
 * Return: 1 if it is a comment, 0 it not
 */
int is_a_comment(char *input)
{
	int i;

	for (i = 0; input[i]; i++)
	{
		if (input[i] == ' ' || input[i] == '\t')
			continue;

		if (input[i] != '#')
			return (0);

		break;
	}

	return (1);
}

/**
 * shell_loop - Loop of shell
 * @datash: data relevant (av, input, args)
 *
 * Return: no return.
 */
void shell_loop(data_shell *datash)
{
	int loop;
	char *input, *without_comnts;

	loop = 1;
	while (loop == 1)
	{
		write(STDIN_FILENO, "^-^ ", 4);
		input = read_line();

		if (input[0] != '\0')
		{
			if (is_a_comment(input) == 1)
			{
				free(input);
				continue;
			}

			without_comnts = _strtok(input, "#");

			if (check_syntax_error(datash, without_comnts) == 1)
			{
				datash->status = 2;
				free(input);
				continue;
			}

			loop = split_commands(datash, without_comnts);
			datash->counter += 1;
			free(input);
		}
		else
		{
			loop = 0;
			free(input);
		}
	}
}
