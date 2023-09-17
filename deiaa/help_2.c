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
