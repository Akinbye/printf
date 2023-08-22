#include "main.h"

/**
 *handle_p - prints arguments
 *@format: formated string
 *@my_list: argument list
 *@ind: ind
 *@buffer: buffer array
 *@flags: active flags
 *@width: get width
 *@precision: get precision
 *@size: size
 *Return: integer
 */
int handle_p(const char *format, int *ind, va_list my_list,
		char buffer[], int flags, int width, int precision, int size)
{
	int i, len = 0, all_chars = -1;
	format_t format_types[] = {
		{'c', print_c}, {'s', print_s}, {'%', print_per},
		{'i', print_i}, {'d', print_i}, {'b', print_b},
		{'u', print_u}, {'o', print_o}, {'x', print_x},
		{'X', print_X}, {'p', print_p}, {'S', print_non},
		{'r', print_r}, {'R', print_rot}, {'\0', NULL}
	};

	for (i = 0; format_types[i].format != '\0'; i++)
	{
		if (format[*ind] == format_types[i].format)
			return (format_types[i].fn(my_list, buffer, flags, width,
						precision, size));
	}
	if (format_types[i].format == '\0')
	{
		if (format[*ind] == '\0')
			return (-1);
		len += write(1, "%%", 1);

		if (format[*ind - 1] == ' ')
			len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);

			while (format[*ind] != ' ' && format[*ind] != '%')
				--(*ind);
			if (format[*ind] == ' ')
				--(*ind);
			return (1);
		}
		len += write(1, &format[*ind], 1);
		return (len);
	}
	return (all_chars);
}
