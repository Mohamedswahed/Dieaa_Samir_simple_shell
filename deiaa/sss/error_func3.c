#include "main.h"
/*
 # strcat_cd - concatenates message for cd error.
 # @datash: directory for data relevant 
 # @masg: message to print
 # @err: output message
 # @ver_str: counter lines
 # Return: error message
 */
char *strcat_cd(data_shell *datash, char *masg, char *err, char *ver_str)
{
	char *ilgal_flg;
	_strcpy(err, datash->av[0]);
	_strcat(err, ": ");
	_strcat(err, ver_str);
	_strcat(err, ": ");
	_strcat(err, datash->args[0]);
	_strcat(err, masg);
	if (datash->args[1][0] == '-')
	{
		ilgal_flg = malloc(3);
		ilgal_flg[0] = '-';
		ilgal_flg[1] = datash->args[1][1];
		ilgal_flg[2] = '\0';
		_strcat(err, ilgal_flg);
		free(ilgal_flg);
	}
	else
	{
		_strcat(err, datash->args[1]);
	}
	_strcat(err, "\n");
	_strcat(err, "\0");
	return (err);
}

/*
 # get_error - calls the error according the builtin, syntax or permission
 # @datash: The data struct.
 # @eval: The value of the error
 # Return: error
 */
int get_err(data_shell *datash, int eval)
{
	char *err;
	switch (eval)
	{
	case -1:
		err = err_env(datash);
		break;
	case 126:
		err = err_path_126(datash);
		break;
	case 127:
		err = err_not_found(datash);
		break;
	case 2:
		if (_strcmp("exit", datash->args[0]) == 0)
			err = err_exit_shell(datash);
		else if (_strcmp("cd", datash->args[0]) == 0)
			err = err_get_cd(datash);
		break;
	}
	if (err)
	{
		write(STDERR_FILENO, err, _strlen(err));
		free(err);
	}
	datash->status = eval;
	return (eval);
}
