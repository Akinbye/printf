#include "main.h"
/**
 *_printf - produces output according to c,s,% format specifiers
 *@format: holds the first argument of the function
 *Return: Returns the corresponding output based on the format
 */
int _printf(const char *format, ...)
{
	int i = 0;

	va_list other_args;

	if (format == NULL)
		return (-1);
	va_start(other_args, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1); }
		else
		{
			format++;
			if (*format == 'c')
			{
				int c = va_arg(other_args, int);

				write(1, &c, 1);
				i++; }
			else if (*format == 's')
			{
				char *s = va_arg(other_args, char *);

				write(1, s, strlen(s));
				i++; }
			else if (*format == '%')
			{
				int a = va_arg(other_args, int);

				write(1, &a, 1); }
		}
		format++;
	}
	va_end(other_args);
	return (0);
}
