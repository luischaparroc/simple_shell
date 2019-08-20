#include "holberton.h"

/**
 * exec_line - finds builtins and commands
 *
 * @args: arguments
 * @input: input arguments
 * Return: 1 on success.
 */
int exec_line(char **args, char *input)
{
	int (*builtin)(char **args);

	if (args[0] == NULL)
		return (1);

	builtin = get_builtin(args[0]);

	if (builtin != NULL)
		return (builtin(args));

	return (cmd_exec(args, input));
}
