#include "holberton.h"

/**
 * main - Entry point
 *
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 on success.
 */
int main(int ac, char **av)
{
	data_shell datash;
	(void) ac;

	datash.av = av;
	datash.input = NULL;
	datash.args = NULL;
	datash.status = 0;
	datash.c_error = 0;
	signal(SIGINT, get_sigint);
	shell_loop(&datash);
	return (datash.status);
}
