#include "main.h"

/**
 * exec_line - finds builtins and commands
 * @datash: data relevant (args)
 * Return: success 1.
 */
int exec_line(data_shell *datash)
{
	int (*builtin)(data_shell *datash);
	if (datash->args[0] == NULL)
		return (1);
	builtin = get_builtin(datash->args[0]);
	if (builtin != NULL)
		return (builtin(datash));
	return (cmd_exec(datash));
}

/**
 * exit_shell - exits the shell
 * @datash: data relevant (status and args)
 * Return: success 0.
 */
int exit_shell(data_shell *datash)
{
	unsigned int u_st;
	int is_d;
	int st_l;
	int big_n;
	if (datash->args[1] != NULL)
	{
		u_st = _atoi(datash->args[1]);
		is_d = _isdigit(datash->args[1]);
		st_l = _strlen(datash->args[1]);
		big_n = u_st > (unsigned int)INT_MAX;
		if (!is_d || st_l > 10 || big_n)
		{
			get_err(datash, 2);
			datash->status = 2;
			return (1);
		}
		datash->status = (u_st % 256);
	}
	return (0);
}

