#include "main.h"
/*
 * _strcmp - Function that compares two strings.
 * @s1: type string compared
 * @s2: type string compared
 * Return: Always 0.
 */
int _strcmp(char *s1, char *s2)
{
	int x;
	for (x = 0; s1[x] == s2[x] && s1[x]; x++)
		;
	if (s1[x] > s2[x])
		return (1);
	if (s1[x] < s2[x])
		return (-1);
	return (0);
}

/*
 * rev_string - function to reverse string.
 * @str: input string to be reversed
 * Return: No Return.
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

/*
 * _strspn - gets the length of a prefix substring.
 * @s: initial segment.
 * @accept: accepted bytes.
 * Return: the number of accepted bytes.
 */
int _strspn(char *s, char *accept)
{
	int x, y, b;
	for (x = 0; *(s + x) != '\0'; x++)
	{
		b = 1;
		for (y = 0; *(accept + y) != '\0'; y++)
		{
			if (*(s + x) == *(accept + y))
			{
				b = 0;
				break;
			}
		}
		if (b == 1)
			break;
	}
	return (x);
}

/*
 * _strchr - locates a character in a string,
 * @s: string.
 * @c: character.
 * Return: the pointer to the first occurrence of the character c.
 */
char *_strchr(char *s, char c)
{
	unsigned int x = 0;
	for (; *(s + x) != '\0'; x++)
		if (*(s + x) == c)
			return (s + x);
	if (*(s + x) == c)
		return (s + x);
	return ('\0');
}

/*
 * _strcat - Function to concatenate 2 strings together.
 * @dest: Char pointer the dest of the copied str
 * @src: const char pointer the source of str
 * Return: dest
 */
char *_strcat(char *dest, const char *src)
{
	int x, y;
	for (x = 0; dest[x] != '\0'; x++)
		;
	for (y = 0; src[y] != '\0'; y++)
	{
		dest[x] = src[y];
		x++;
	}
	dest[x] = '\0';
	return (dest);
}
