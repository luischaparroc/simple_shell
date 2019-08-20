#include "holberton.h"

/**
 * get_builtin - builtin that pais the command in the arg
 * @cmd: command
 * Return: function pointer of the builtin command
 *
 */

int (*get_builtin(char *cmd))(char **args)
{
	builtin_t builtin[] = {
		{ "env", _env },
		{ "exit", exit_shell },
		{ NULL, NULL }
	};
	int i;

	for (i = 0; builtin[i].name; i++)
	{
		if (_strcmp(cmd, builtin[i].name) == 0)
			break;
	}

	return (builtin[i].f);
}
