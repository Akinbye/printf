#include "main.h"

/**
 *printable - checks for printable char
 *@c: characters
 *Return: integer
 */
int printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}

/**
 *append - appends hexadecimal code
 *@buffer: array
 *@i: index for appending
 *@ascii_code: ASCII CODE
 *Return: 3
 */
int append(char ascii_code, char buffer[], int i)
{
	char check[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;
	buffer[i++] = '\\';
	buffer[i++] = 'x';
	buffer[i++] = check[ascii_code / 16];
	buffer[i] = check[ascii_code % 16];

	return (3);
}

/**
 *is_digit - checks for digits
 *@c: character
 *Return: integer
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/**
 *convert_s - conversts size of number
 *@number: number to be converted
 *@size: size
 *Return: integer
 */
long int convert_s(long int number, int size)
{
	if (size == S_LONG)
		return (number);
	else if (size == S_SHORT)
		return ((short)number);
	return ((int)number);
}

/**
 *convert_u - casts numbers
 *@number: numbers
 *@size: size
 *Return: integer
 */
long int convert_u(unsigned long int number, int size)
{
	if (size == S_LONG)
		return (number);
	else if (size == S_SHORT)
		return ((unsigned short)number);
	return ((unsigned int)number);
}
