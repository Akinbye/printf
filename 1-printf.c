#include "main.h"

void handle_conversion(const char *format, va_list my_list);
/**
 *printf_int - prints integer
 *@format: format specifier
 *Return: number of argument
 */

void handle_conversion(const char *format, va_list my_list)
{
	int numbers = va_arg(my_list, int);
	write(1, &numbers, 1);
	format++;
}

int printf_int(const char *format, ...)
{
	va_list my_list;

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(my_list, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'd' || *format == 'i')
				handle_conversion(format, my_list);
			else
				_ptchar(*format);
		}
		format++;
	}
	va_end(my_list);
	return (1);
}
