#include "main.h"

/**
 * exit_shell - exits the shell
 *
 * @datash: data relevant (status and args)
 * Return: 0 on success.
 */
int exit_shell(data_shell *datash)
{
	unsigned int u_st;
	int is_dig;
	int str_len;
	int big_num;

	if (datash->args[1] != NULL)
	{
		u_st = _atoi(datash->args[1]);
		is_dig = _isdigit(datash->args[1]);
		str_len = _strlen(datash->args[1]);
		big_num = u_st > (unsigned int)INT_MAX;
		if (!is_dig || str_len > 10 || big_num)
		{
			get_error(datash, 2);
			datash->status = 2;
			return (1);
		}
		datash->status = (u_st % 256);
	}
	return (0);
}

