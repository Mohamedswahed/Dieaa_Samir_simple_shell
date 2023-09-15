#include "main.h"

/*
 # aux_hlp_setenv - Help information to builtin setenv
 # Return: No return
 */
void aux_hlp_setenv(void)
{
	char *hlp = "setenv: setenv (const char *name, const char *value,";
	write(STDOUT_FILENO, hlp, _strlen(hlp));
	hlp = "int replace)\n\t";
	write(STDOUT_FILENO, hlp, _strlen(hlp));
	hlp = "Add a new definition to the environment\n";
	write(STDOUT_FILENO, hlp, _strlen(hlp));
}

/*
 # aux_hlp_alias - Help information to builtin alias.
 # Return: No return
 */
void aux_hlp_alias(void)
{
	char *hlp = "alias: alias [-p] [name[=value]...]\n";
	write(STDOUT_FILENO, hlp, _strlen(hlp));
	hlp = "\tDefine or display aliases.\n ";
	write(STDOUT_FILENO, hlp, _strlen(hlp));
}

/*
 # aux_hlp_cd - Help information to builtin alias.
 # Return: No return
 */
void aux_hlp_cd(void)
{
	char *hlp = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n";
	write(STDOUT_FILENO, hlp, _strlen(hlp));
	hlp = "\tChange the shell working directory.\n ";
	write(STDOUT_FILENO, hlp, _strlen(hlp));
}

/*
 # get_hlp - Retrieves Help messages according builtin
 # @datash: Data struct
 # Return: Return 1
*/
int get_hlp(data_shell *datash)
{
	if (datash->args[1] == 0)
		aux_hlp_general();
	else if (_strcmp(datash->args[1], "setenv") == 0)
		aux_hlp_setenv();
	else if (_strcmp(datash->args[1], "env") == 0)
		aux_hlp_env();
	else if (_strcmp(datash->args[1], "unsetenv") == 0)
		aux_hlp_unsetenv();
	else if (_strcmp(datash->args[1], "help") == 0)
		aux_hlp();
	else if (_strcmp(datash->args[1], "exit") == 0)
		aux_hlp_exit();
	else if (_strcmp(datash->args[1], "cd") == 0)
		aux_hlp_cd();
	else if (_strcmp(datash->args[1], "alias") == 0)
		aux_hlp_alias();
	else
		write(STDERR_FILENO, datash->args[0],
		      _strlen(datash->args[0]));
	datash->status = 0;
	return (1);
}
