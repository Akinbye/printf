#include "main.h"

int _printf(const char *format, ...);

/**
 *print_c - prints character
 *@my_arg: arguments
 *@buffer: buffer array
 *@flags: active flags
 *@width: width
 *@precision: precision
 *@size: size
 *Return: integer
 */
int print_c(va_list my_arg, char buffer[],
		int flags, int width, int precision, int size)
{
	char c = va_arg(my_arg, int);

	return (handle_w(c, buffer, flags, width, precision, size));
}

/**
 *print_s - prints string
 *@my_arg: arguments
 *@buffer: Buffer array to handle print
 *@flags:  Calculates active flags
 *@width: get width.
 *@precision: Precision specification
 *@size: Size specifier
 *Return: integer
 */
int print_s(va_list my_arg, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, i;
	char *string = va_arg(my_arg, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (string == NULL)
	{
		string = "(null)";
		if (precision >= 6)
			string = "      ";
	}
	while (string[length] != '\0')
		length++;
	if (precision >= 0 && precision < length)
		length = precision;
	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &string[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &string[0], length);
			return (width);
		}
	}
	return (write(1, string, length));
}

/**
 *print_per - prints percentage sign
 *@my_arg: arguments
 *@buffer: Buffer array to handle print
 *@flags:  Calculates active flags
 *@width: get width.
 *@precision: Precision specification
 *@size: Size specifier
 *Return: integer
 */
int print_per(va_list my_arg, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(my_arg);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/**
 *print_i - prints integer
 *@my_arg: arguments
 *@buffer: Buffer array to handle print
 *@flags:  Calculates active flags
 *@width: get width.
 *@precision: Precision specification
 *@size: Size specifier
 *Return: integer
 */
int print_i(va_list my_arg, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int negative = 0;
	long int m = va_arg(my_arg, long int);
	unsigned long int number;

	m = convert_s(m, size);

	if (m == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	number = (unsigned long int)m;

	if (m < 0)
	{
		number = (unsigned long int)((-1) * m);
		negative = 1;
	}
	while (number > 0)
	{
		buffer[i--] = (number % 10) + '0';
		number /= 10;
	}
	i++;
	return (write_n(negative, i, buffer, flags, width,
				precision, size));
}

/**
 *print_b - prints binary
 *@my_arg: arguments
 *@buffer: Buffer array to handle print
 *@flags:  Calculates active flags
 *@width: get width.
 *@precision: Precision specification
 *@size: Size specifier
 *Return: integer
 */
int print_b(va_list my_arg, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int a, b, c, sum;
	unsigned int m[32];
	int cnt;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	a = va_arg(my_arg, unsigned int);
	b = 2147483648;
	m[0] = a / b;

	for (c = 1; c < 32; c++)
	{
		b /= 2;
		m[c] = (a / b) % 2;
	}
	for (c = 0, sum = 0, cnt = 0; c < 32; c++)
	{
		sum += m[c];
		if (sum || c == 31)
		{
			char y = '0' + m[c];

			write(1, &y, 1);
			cnt++;
		}
	}
	return (cnt);
}
