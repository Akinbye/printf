#include "main.h"
#include <stdio.h>

void handle_conversion(char specifier, va_list my_list);
void print_buffer(char buffer[], int *buff_ind);

/**
 *print_buffer - prints buffer
 *@buffer: buffer to be printed
 *@buff_ind: integer
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);
	*buff_ind = 0;
}

/**
 *handle_conversion - handles conversion
 *@specifier: specifier
 *@my_list: argument list
 *Return: number of argument
 */

void handle_conversion(char specifier, va_list my_list)
{

	if (specifier == 'd' || specifier == 'i')
	{
		int i;
		int num = va_arg(my_list, int);
		char buffer[12];
		int size = sprintf(buffer, "%d", num);

		for (i = 0; i < size; i++)
		{
			_ptchar(buffer[i]);
		}
	}
}

/**
 *printf_int - prints integer
 *@format: format specifier
 *Return: 0
 */

int printf_int(const char *format, ...)
{
	int count = 0;
	va_list my_list;

	va_start(my_list, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			handle_conversion(*format, my_list);
			count++;
		}
		else
		{
			_ptchar(*format);
			count++;
		}
		format++;
	}
	va_end(my_list);
	return (count);
}
