#include "holberton.h"

/**
 * aux_help_env - Help information for the builtin env
 */
void aux_help_env(void)
{
	char *help = "_env: env builtin\n Print the enviroment of the shell.\n";

	write(STDOUT_FILENO, help, _strlen(help));
}
/**
 * aux_help_gen - Generic help information for the help builtin
 */
void aux_help_gen(void)
{
	char *help = "_help: help builtin\n Print the generic from shell.\n";

	write(STDOUT_FILENO, help, _strlen(help));
}
/**
 * aux_help_exit - Help information fot the builint exit
 */
void aux_help_exit(void)
{
	char *help = "_exit: exit [status]\n Exit shell program.\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "status arg is the int used to exit the program";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "exit value 0";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "No argument given";
}
/**
 * help_all - Displays all possible builtin shellby commands.
 */
void aux_help_all(void)
{
	char *help = "Internal defined builtin commands for the shell.\n";


	write(STDOUT_FILENO, help, _strlen(help));
	help = "Type 'help' to see list.\nType 'help name' to find ";
}
