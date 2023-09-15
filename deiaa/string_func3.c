#include "main.h"
/*
 * *_strcpy - Copy string in pointer src.
 * @dest: dest of copied str
 * @src: the string source pointer.
 * Return: the dest.
 */
char *_strcpy(char *dest, char *src)
{
	size_t i;
	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}
