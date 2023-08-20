#include "main.h"

/**
 *print_int - prints integer
 *@format: format given
 *@...: variable
 *Return: 0
 */
int print_int(const char *format, ...)
{
	int n = 0;
	va_list my_list;

	if (format == NULL)
		return (-1);
	va_start(my_list, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			n++;
		}
		else
		{
			format++;
			if (*format == 'd')
			{
				int d = va_arg(my_list, int);

				write(1, &d, 4);
				n++;
			}
			else if (*format == 'i')
			{
				int i = va_arg(my_list, int);

				write(1, &i, 4);
				n++;
			}
		}
		format++;
	}
	va_end(my_list);
	return (n);
}
