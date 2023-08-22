#include "main.h"

void print_buff(char buffer[], int *buff_ind);

/**
 *_printf - prints formatted text to the stdoutput
 *@format: the first argument in the function
 *Return: Returns an integer
 */
int _printf(const char *format, ...)
{
	int i, strcnt = 0, cnt = 0;

	int flags, width, precision, size, buff_ind = 0;
	va_list my_list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(my_list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buff(buffer, &buff_ind);
			cnt++;
		}
		else
		{
			print_buff(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, my_list);
			precision = get_precision(format, &i, my_list);
			size = get_size(format, &i);
			++i;
			strcnt = handle_p(format, &i, my_list, buffer,
					flags, width, precision, size);
			if (strcnt == -1)
				return (-1);
			cnt += strcnt;
		}
	}
	print_buff(buffer, &buff_ind);
	va_end(my_list);
	return (cnt);
}

/**
 *print_buff - prints buffer
 *@buffer: buffer array
 *@buff_ind: index
 */
void print_buff(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);
	*buff_ind = 0;
}
