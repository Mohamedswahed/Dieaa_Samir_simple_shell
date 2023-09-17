#include "main.h"
/*
 # repeated_char - count repetitions of char.
 # @in: string input
 # @x: index
 # Return: repetitions
 */
int repeated_char(char *in, int x)
{
	if (*(in - 1) == *in)
		return (repeated_char(in - 1, x + 1));

	return (x);
}

/*
 # err_sep_op - finds syntax errors.
 # @in: string input
 # @x: index
 # @lst: the last read character
 # Return:  if error Return error index, 0 in case of no errors.
 */
int err_sep_op(char *in, int x, char lst)
{
	int cnt;
	cnt = 0;
	if (*in == '\0')
		return (0);
	if (*in == ' ' || *in == '\t')
		return (err_sep_op(in + 1, x + 1, lst));
	if (*in == ';')
		if (lst == '|' || lst == '&' || lst == ';')
			return (x);
	if (*in == '|')
	{
		if (lst == ';' || lst == '&')
			return (x);
		if (lst == '|')
		{
			cnt = repeated_char(in, 0);
			if (cnt == 0 || cnt > 1)
				return (x);
		}
	}
	if (*in == '&')
	{
		if (lst == ';' || lst == '|')
			return (x);
		if (lst == '&')
		{
			cnt = repeated_char(in, 0);
			if (cnt == 0 || cnt > 1)
				return (x);
		}
	}
	return (err_sep_op(in + 1, x + 1, *in));
}

/*
 # first_char - finds index of the first char.
 # @in: in string.
 # @x: index
 # Return: 1 if there is an err. 0 in other case.
 */
int first_char(char *in, int *x)
{
	for (*x = 0; in[*x]; *x += 1)
	{
		if (in[*x] == ' ' || in[*x] == '\t')
			continue;
		if (in[*x] == ';' || in[*x] == '|' || in[*x] == '&')
			return (-1);
		break;
	}
	return (0);
}

/*
 # print_syntax_err - prints when a syntax error is found
 # @datash: data structure
 # @in: input string
 # @x: error index
 # @b: error message control
 # Return: No Return
 */
void print_syntax_err(data_shell *datash, char *in, int x, int b)
{
	char *masg, *masg2, *masg3, *err, *cnter;
	int l;
	if (in[x] == ';')
	{
		if (b == 0)
			masg = (in[x + 1] == ';' ? ";;" : ";");
		else
			masg = (in[x - 1] == ';' ? ";;" : ";");
	}
	if (in[x] == '|')
		masg = (in[x + 1] == '|' ? "||" : "|");
	if (in[x] == '&')
		masg = (in[x + 1] == '&' ? "&&" : "&");
	masg2 = ": Syntax err: \"";
	masg3 = "\" unexpected\n";
	cnter = aux_itoa(datash->counter);
	l = _strlen(datash->av[0]) + _strlen(cnter);
	l += _strlen(masg) + _strlen(masg2) + _strlen(masg3) + 2;
	err = malloc(sizeof(char) * (l + 1));
	if (err == 0)
	{
		free(cnter);
		return;
	}
	_strcpy(err, datash->av[0]);
	_strcat(err, ": ");
	_strcat(err, cnter);
	_strcat(err, masg2);
	_strcat(err, masg);
	_strcat(err, masg3);
	_strcat(err, "\0");
	write(STDERR_FILENO, err, l);
	free(err);
	free(cnter);
}

/*
 # check_syntax_err - Function to print syn. error
 # @datash: data structure
 # @in: string as input
 # Return: 1 in case if there is an err & 0 if not
 */
int check_syntax_err(data_shell *datash, char *in)
{
	int strt = 0;
	int f_char = 0;
	int x = 0;
	f_char = first_char(in, &strt);
	if (f_char == -1)
	{
		print_syntax_err(datash, in, strt, 0);
		return (1);
	}
	x = err_sep_op(in + strt, 0, *(in + strt));
	if (x != 0)
	{
		print_syntax_err(datash, in, strt + x, 1);
		return (1);
	}
	return (0);
}