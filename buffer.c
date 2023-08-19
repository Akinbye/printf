#include "main.h"
void print_buffer(char buffer[], int *buff_ind);

/**
 *_printf - print function
 *@format: format given
 *Return: 0
 */
int _printf(const char *format, ...)
{
	int n, printed = 0, all_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list my_list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(my_list, format);

	for (n = 0; format && format[n] != '\0'; n++)
	{
		if (format[n] != '%')
		{
			buffer[buff_ind++] = format[n];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &biff_ind);
			/*write(1, &format[n], 1);*/
			all_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &n);
			width = get_width(format, &n, my_list);
			precision = get_precision(format, &n, my_list);
			size = get_size(format, &n);
			++n;
			printed = handle_print(format, &n, my_list, buffer,
					flags, width, precision, size);

			if (printed == -1)
				return (-1);
			all_chars += printed;
		}
	}
	print_buffer(buffer, &buff_ind);
	va_end(my_list);
	return (all_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
