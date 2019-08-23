#include "holberton.h"

/**
 * exit_shell - exits the shell
 *
 * @datash: data relevant (status and args)
 * Return: 0 on success.
 */
int exit_shell(data_shell *datash)
{
	unsigned int ustatus;

	if (datash->args[1] != NULL)
	{
		ustatus = _atoi(datash->args[1]);
		if (ustatus > (unsigned int)INT_MAX)
		{
			get_error(datash, 2);
			datash->status = 2;
			return (1);
		}
		ustatus = _atoi(datash->args[1]);
		datash->status = (ustatus % 256);
	}
	return (0);
}
