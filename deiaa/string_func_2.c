#include "main.h"

/**
 * _strdup - string duplication in heap memory.
 * @str: Type character pointer string
 * Return: duplicated string
 */
char *_strdup(const char *str)
{
	char *n;
	size_t len;

	len = _strlen(str);
	n = malloc(sizeof(char) * (len + 1));
	if (n == NULL)
		return (NULL);
	_memcpy(n, str, len + 1);
	return (n);
}

/**
 * _strlen - Returns string length.
 * @str: Type char pointer
 * Return: Always 0.
 */
int _strlen(const char *str)
{
	int len;

	for (len = 0; str[len] != 0; len++)
	{
	}
	return (len);
}

/**
 * cmp_chars - compare strings characters
 * @str: input string.
 * @delim: delimiter.
 *
 * Return: 1 if are equals, 0 if not.
 */
int cmp_chars(char str[], const char *delim)
{
	unsigned int x, y, z;

	for (x = 0, z = 0; str[x]; x++)
	{
		for (y = 0; delim[y]; y++)
		{
			if (str[x] == delim[y])
			{
				z++;
				break;
			}
		}
	}
	if (x == z)
		return (1);
	return (0);
}

/**
 * _strtok - splits a string by delimiter.
 * @str: input string.
 * @delim: delimiter.
 *
 * Return: string splited.
 */
char *_strtok(char str[], const char *delim)
{
	static char *splitted, *str_end;
	char *str_start;
	unsigned int x, b;

	if (str != NULL)
	{
		if (cmp_chars(str, delim))
			return (NULL);
		splitted = str; /*Store first address*/
		x = _strlen(str);
		str_end = &str[x]; /*Store last address*/
	}
	str_start = splitted;
	if (str_start == str_end) /*Reaching the end*/
		return (NULL);

	for (b = 0; *splitted; splitted++)
	{
		/*Breaking loop finding the next token*/
		if (splitted != str_start)
			if (*splitted && *(splitted - 1) == '\0')
				break;
		/*Replacing delimiter for null char*/
		for (x = 0; delim[x]; x++)
		{
			if (*splitted == delim[x])
			{
				*splitted = '\0';
				if (splitted == str_start)
					str_start++;
				break;
			}
		}
		if (b == 0 && *splitted) /*Str != Delim*/
			b = 1;
	}
	if (b == 0) /*Str == Delim*/
		return (NULL);
	return (str_start);
}

/**
 * _isdigit - To verify that input string is a number
 *
 * @str: input string
 * Return: 1 if string is a number. 0 if not.
 */
int _isdigit(const char *str)
{
	unsigned int x;

	for (x = 0; str[x]; x++)
	{
		if (str[x] < 48 || str[x] > 57)
			return (0);
	}
	return (1);
}
