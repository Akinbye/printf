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
	write(1, &numbers, sizeof(int));
	format++;

}

int printf_int(const char *format, ...)
{
	int n = 0;
	va_list my_list;

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(my_list, format);

	while (*format)
	{
		if (format[n] == '%')
		{
			format++;
			if (format[n + 1] == 'd' || format[n + 1] == 'i')
			{
				handle_conversion(format, my_list);
				n++;
			}
			else
				_ptchar(*format);
		}
		format++;
	}
	va_end(my_list);
	return (1);
}
