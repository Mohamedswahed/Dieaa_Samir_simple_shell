#include "main.h"
/*
 # free_rvar_list - Frees r_var list
 # @hd: Linked list head.
 # Return: No return.
 */
void free_rvar_list(r_var **hd)
{
	r_var *tmp;
	r_var *c;
	if (hd != NULL)
	{
		c = *hd;
		while ((tmp = c) != NULL)
		{
			c = c->next;
			free(tmp);
		}
		*hd = NULL;
	}
}

/*
 # aux_itoa - Converts int ---> string.
 # @num: Integer number
 # Return: String.
 */
char *aux_itoa(int num)
{
	unsigned int num1;
	int l = get_len(num);
	char *buffer;
	buffer = malloc(sizeof(char) * (l + 1));
	if (buffer == 0)
		return (NULL);
	*(buffer + l) = '\0';
	if (num < 0)
	{
		num1 = num * -1;
		buffer[0] = '-';
	}
	else
	{
		num1 = num;
	}
	l--;
	do {
		*(buffer + l) = (num1 % 10) + '0';
		num1 = num1 / 10;
		l--;
	}
	while (num1 > 0)
		;
	return (buffer);
}

/*
 # get_len - Get the number length.
 # @num: type int number.
 # Return: Number length.
 */
int get_len(int num)
{
	unsigned int num1;
	int l = 1;
	if (num < 0)
	{
		l++;
		num1 = num * -1;
	}
	else
	{
		num1 = num;
	}
	while (num1 > 9)
	{
		l++;
		num1 = num1 / 10;
	}
	return (l);
}

/*
 # _atoi - Converts String ----> Integer.
 # @s: Input string.
 # Return: Integer.
 */
int _atoi(char *str)
{
	unsigned int pn = 1, m = 1, cnt = 0, size = 0, oi = 0, x;
	while (*(str + cnt) != '\0')
	{
		if (size > 0 && (*(str + cnt) < '0' || *(str + cnt) > '9'))
			break;
		if (*(str + cnt) == '-')
			pn *= -1;
		if ((*(str + cnt) >= '0') && (*(str + cnt) <= '9'))
		{
			if (size > 0)
				m *= 10;
			size++;
		}
		cnt++;
	}
	for (x = cnt - size; x < cnt; x++)
	{
		oi = oi + ((*(str + x) - 48) * m);
		m /= 10;
	}
	return (oi * pn);
}
