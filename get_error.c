#include "main.h"

/**
 * get_error - calls the err according the builtin, syntax or permission
 * @datash: data structure that contains arguments
 * @evaluate: err value
 * Return: err
 */
int get_error(data_shell *datash, int evaluate)
{
	char *err;

	switch (evaluate)
	{
	case -1:
		err = error_env(datash);
		break;
	case 126:
		err = error_path_126(datash);
		break;
	case 127:
		err = error_not_found(datash);
		break;
	case 2:
		if (_strcmp("exit", datash->args[0]) == 0)
			err = error_exit_shell(datash);
		else if (_strcmp("cd", datash->args[0]) == 0)
			err = error_get_cd(datash);
		break;
	}

	if (err)
	{
		write(STDERR_FILENO, err, _strlen(err));
		free(err);
	}

	datash->status = evaluate;
	return (evaluate);
}

