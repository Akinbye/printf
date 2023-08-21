#include "main.h"
#include <stdio.h>

void handle_conversion(char specifier, va_list my_list);
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
		char buffer[10];
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
	int n = 0;
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
		}
		else
			_ptchar(*format);
		format++;
	}
	va_end(my_list);
	return (n);
}
