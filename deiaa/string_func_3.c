
#include "main.h"

/**
 * rev_string - reverses a string.
 * @str: input string.
 * Return: no return.
 */
void rev_string(char *str)
{
	int cnt = 0, x, y;
	char *str2, tmp;

	while (cnt >= 0)
	{
		if (str[cnt] == '\0')
			break;
		cnt++;
	}
	str2 = str;

	for (x = 0; x < (cnt - 1); x++)
	{
		for (y = x + 1; y > 0; y--)
		{
			tmp = *(str2 + y);
			*(str2 + y) = *(str2 + (y - 1));
			*(str2 + (y - 1)) = tmp;
		}
	}
}
