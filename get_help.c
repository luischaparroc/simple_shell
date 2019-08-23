#include "holberton.h"

/**
 * get_help
 * @args:
 */
int get_help(char **args)
{

	if (args[0] == 0)
		aux_help_env();
		else if (_strcmp(args[0], "env") == 0)
			aux_help_env();
		else if (_strcmp(args[0], "general") == 0)
			aux_help_gen();
		else if (_strcmp(args[0], "exit") == 0)
			aux_help_exit();
		else
			write(STDERR_FILENO, prgname, _strlen(prgname));

	return (0);
}
