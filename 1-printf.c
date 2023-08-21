#include "main.h"

void handle_conversion(int value);

/**
 *handle_conversion - handles conversion
 *@value: argument list
 *Return: number of argument
 */

void handle_conversion(int value)
{
	int index, num_digits = 0;
	char buffer[12];

	if (value < 0)
	{
		buffer[0] = '-';
		value = -value;
	}
	index = num_digits + (value < 0 ? 1 : 0);
	buffer[index] = '\0';

	while (value > 0)
	{
		index--;
		buffer[index] = '0' + (value % 10);
		value /= 10;
	}
	_ptchar(*(&buffer[index]));
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
		if (*format != '%')
		{
			_ptchar(*format);
			count++;
		}
		else
		{
			format++;
			if (*format == 'd' || *format == 'i')
			{
				int value = va_arg(my_list, int);

				handle_conversion(value);
				count++;
			}
		}
		format++;
	}
	va_end(my_list);
	return (count);
}
