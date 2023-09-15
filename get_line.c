#include "main.h"

/**
 * bring_line - assigns the line var for get_line
 * @lineptr: Buffer that store the inpt str
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
 * get_line - Read inpt from stream
 * @lineptr: buffer that stores the inpt
 * @n: size of lineptr
 * @stream: stream to read from
 * Return: The number of bytes
 */
ssize_t get_line(char **lineptr, size_t *n, FILE *stream)
{
	int x;
	static ssize_t inpt;
	ssize_t ret_val;
	char *buffer;
	char t = 'z';

	if (inpt == 0)
		fflush(stream);
	else
		return (-1);
	inpt = 0;

	buffer = malloc(sizeof(char) * BUFSIZE);
	if (buffer == 0)
		return (-1);
	while (t != '\n')
	{
		x = read(STDIN_FILENO, &t, 1);
		if (x == -1 || (x == 0 && inpt == 0))
		{
			free(buffer);
			return (-1);
		}
		if (x == 0 && inpt != 0)
		{
			inpt++;
			break;
		}
		if (inpt >= BUFSIZE)
			buffer = _realloc(buffer, inpt, inpt + 1);
		buffer[inpt] = t;
		inpt++;
	}
	buffer[inpt] = '\0';
	bring_line(lineptr, n, buffer, inpt);
	ret_val = inpt;
	if (x != 0)
		inpt = 0;
	return (ret_val);
}

