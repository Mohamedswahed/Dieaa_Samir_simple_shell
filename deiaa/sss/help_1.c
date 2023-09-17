#include "main.h"
/*
 # aux_hlp - Help information to builtin help.
 # Return: No return
 */
void aux_hlp(void)
{
	char *hlp = "hlp: hlp [-dms] [pattern ...]\n";
	write(STDOUT_FILENO, hlp, _strlen(hlp));
	hlp = "\tDisplay information about builtin commands.\n ";
	write(STDOUT_FILENO, hlp, _strlen(hlp));
	hlp = "Displays brief summaries of builtin commands.\n";
	write(STDOUT_FILENO, hlp, _strlen(hlp));
}

/*
 # aux_hlp_general - Entry for Help information to Help builtin
 # Return: No return
 */
void aux_hlp_general(void)
{
	char *hlp = "$ bash, version 1.0(1)-release\n";
	write(STDOUT_FILENO, hlp, _strlen(hlp));
	hlp = "These commands are defined internally.Type 'hlp' to see the list";
	write(STDOUT_FILENO, hlp, _strlen(hlp));
	hlp = "Type 'hlp name' to find out more about the function 'name'.\n\n ";
	write(STDOUT_FILENO, hlp, _strlen(hlp));
	hlp = " alias: alias [name=['string']]\n cd: cd [-L|[-P [-e]] [-@]] ";
	write(STDOUT_FILENO, hlp, _strlen(hlp));
	hlp = "[dir]\nexit: exit [n]\n  env: env [option] [name=value] [command ";
	write(STDOUT_FILENO, hlp, _strlen(hlp));
	hlp = "[args]]\n  setenv: setenv [variable] [value]\n  unsetenv: ";
	write(STDOUT_FILENO, hlp, _strlen(hlp));
	hlp = "unsetenv [variable]\n";
	write(STDOUT_FILENO, hlp, _strlen(hlp));
}

/*
 # aux_hlp_unsetenv - Help information to builtin unsetenv
 # Return: No return
 */
void aux_hlp_unsetenv(void)
{
	char *hlp = "unsetenv: unsetenv (const char *name)\n\t";
	write(STDOUT_FILENO, hlp, _strlen(hlp));
	hlp = "Remove an entry completely from the environment\n";
	write(STDOUT_FILENO, hlp, _strlen(hlp));
}

/*
 # aux_hlp_env - Help information to builtin env
 # Return: No return
 */
void aux_hlp_env(void)
{
	char *hlp = "env: env [option] [name=value] [command [args]]\n\t";
	write(STDOUT_FILENO, hlp, _strlen(hlp));
	hlp = "Print the enviroment of the shell.\n";
	write(STDOUT_FILENO, hlp, _strlen(hlp));
}

/*
 # aux_hlp_exit - Help information to the builint exit
 # Return: No return
 */
void aux_hlp_exit(void)
{
	char *hlp = "exit: exit [n]\n Exit shell.\n";
	write(STDOUT_FILENO, hlp, _strlen(hlp));
	hlp = "Exits the shell with a status of N. If N is ommited, the exit";
	write(STDOUT_FILENO, hlp, _strlen(hlp));
	hlp = "statusis that of the last command executed\n";
	write(STDOUT_FILENO, hlp, _strlen(hlp));
}
