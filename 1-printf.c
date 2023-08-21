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
		int number = va_arg(my_list, int);
		char buffer[12];
		int size = sprintf(buffer, "%d", number);

		_ptchar(*buffer);
		size++;
	}
}

/**
 *printf_int - prints integer
 *@format: format specifier
 *Return: 0
 */

int printf_int(const char *format, ...)
{
	int n, count = 0;
	va_list my_list;

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(my_list, format);

	for (n = 0; format[n] != '\0'; n++)
	{
		if (format[n] == '%')
		{
			format++;
			handle_conversion(*format, my_list);
			n++;
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
