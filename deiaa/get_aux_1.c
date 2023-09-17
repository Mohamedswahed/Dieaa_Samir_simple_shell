#include "main.h"

/**
 * get_err - calls the error according the builtin
 * @datash: data structure
 * @eval: error value
 * Return: error
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

/**
 * get_hlp - Retrieves help messages as builtin.
 * @datash: Data structure
 * Return: Return 1
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

/**
 * bring_line - assigns the line var
 * @lineptr: Buffer that store the input str
 * @buffer: str that is been called to line
 * @n: size of line
 * @y: size of buffer
 */
void bring_line(char **lineptr, size_t *n, char *buffer, size_t y)
{
	if (*lineptr == NULL)
	{
		if  (y > BUFSIZE)
			*n = y;
		else
			*n = BUFSIZE;
		*lineptr = buffer;
	}
	else if (*n < y)
	{
		if (y > BUFSIZE)
			*n = y;
		else
			*n = BUFSIZE;
		*lineptr = buffer;
	}
	else
	{
		_strcpy(*lineptr, buffer);
		free(buffer);
	}
}

/**
 * get_line - Read input from stream
 * @lineptr: buffer that stores the input
 * @n: size of lineptr
 * @stream: stream to read from
 * Return: The number of bytes
 */
ssize_t get_line(char **lineptr, size_t *n, FILE *stream)
{
	int x;
	static ssize_t inp;
	ssize_t ret_val;
	char *buffer;
	char t = 'z';

	if (inp == 0)
		fflush(stream);
	else
		return (-1);
	inp = 0;

	buffer = malloc(sizeof(char) * BUFSIZE);
	if (buffer == 0)
		return (-1);
	while (t != '\n')
	{
		x = read(STDIN_FILENO, &t, 1);
		if (x == -1 || (x == 0 && inp == 0))
		{
			free(buffer);
			return (-1);
		}
		if (x == 0 && inp != 0)
		{
			inp++;
			break;
		}
		if (inp >= BUFSIZE)
			buffer = _realloc(buffer, inp, inp + 1);
		buffer[inp] = t;
		inp++;
	}
	buffer[inp] = '\0';
	bring_line(lineptr, n, buffer, inp);
	ret_val = inp;
	if (x != 0)
		inp = 0;
	return (ret_val);
}

