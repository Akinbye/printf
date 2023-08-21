#include "main.h"

/**
 *_printf - prints formatted text to the stdoutput
 *@format: the first argument in the function
 *Return: Returns an integer
 */
int _printf(const char *format, ...)
{
	int i, strcnt, cnt = 0;

	va_list other_args;

	if (format == NULL)
		return (-1);

	va_start(other_args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
			_ptchar(format[i]);
		else if (format[i + 1] == '%')
		{
			_ptchar('%');
			i++;
		}
		else if (format[i + 1] == 'c')
		{
			_ptchar(va_arg(other_args, int));
			i++;
		}
		else if (format[i + 1] == 's')
		{
			strcnt = put_s(va_arg(other_args, char *));
			i++;
			cnt += strcnt;
		}
		cnt++;
	}
	va_end(other_args);
	return (cnt);
}
