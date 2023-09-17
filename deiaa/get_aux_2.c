#include "main.h"

/**
 * get_sigint - Handle the crtl + c call in prompt
 * @sig: Signal handler
 */
void get_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n$ ", 3);
}

/**
 * get_builtin - builtin that pais the command
 * @cmd: command
 * Return: function pointer
 */
int (*get_builtin(char *cmd))(data_shell *)
{
	builtin_t builtin[] = {
		{ "env", _env },
		{ "exit", exit_shell },
		{ "setenv", _setenv },
		{ "unsetenv", _unsetenv },
		{ "cd", cd_shell },
		{ "help", get_hlp },
		{ NULL, NULL }
	};
	int x;

	for (x = 0; builtin[x].name; x++)
	{
		if (_strcmp(builtin[x].name, cmd) == 0)
			break;
	}
	return (builtin[x].f);
}
