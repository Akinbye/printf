#include "main.h"

/**
 *_printf - Handle the following conversion specifiers
 *@format: constant format given
 *@...: variables
 *Return: 0
 */
int _printf(const char *format, ...)
{
	int n = 0;

	va_list all;

	if (format == NULL)
		return (-1);
	va_start(all, format);

	while (*format)
	{
		if (*format != '%')
			write(1, format, 1);
		else
		{
			format++;
			if (*format == 'd')
			{
				int d = va_arg(all, int);

				write(1, &d, 4);
				n++;
			}
			else if (*format == 'i')
			{
				int i = va_arg(all, int);

				write(1, &i, 4);
				n++;
			}
		}
		format++;
	}
	va_end(all);
	return (n);
}
