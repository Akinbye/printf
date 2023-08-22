#include "main.h"
/**
 *print_u - prints unsigned numbers
 *@my_arg: arguments
 *@buffer: Buffer array to handle print
 *@flags: Calculates active flags
 *@width: get width
 *@precision: Precision specification
 *@size: Size specifier
 *Return: integer
 */
int print_u(va_list my_arg, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int number = va_arg(my_arg, unsigned long int);

	number = convert_u(number, size);

	if (number == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buffer[i--] = (number % 10) + '0';
		number /= 10;
	}
	i++;
	return (write_un(0, i, buffer, flags, width, precision, size));
}

/**
 *print_o - prints octal notation
 *@my_arg: arguments
 *@buffer: Buffer array to handle print
 *@flags: Calculates active flags
 *@width: get width
 *@precision: Precision specification
 *@size: Size specifier
 *Return: integer
 */
int print_o(va_list my_arg, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int number = va_arg(my_arg, unsigned long int);
	unsigned long int my_number = number;

	UNUSED(width);

	number = convert_u(number, size);

	if (number == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buffer[i--] = (number % 8) + '0';
		number /= 8;
	}
	if (flags & F_HASH && my_number != 0)
		buffer[i--] = '0';
	i++;
	return (write_un(0, i, buffer, flags, width, precision, size));
}

/**
 *print_x - hexadecimal notation
 *@my_arg: arguments
 *@buffer: Buffer array to handle print
 *@flags: Calculates active flags
 *@width: get width
 *@precision: Precision specification
 *@size: Size specifier
 *Return: integer
 */
int print_x(va_list my_arg, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hex(my_arg, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/**
 *print_X - upper hexadecimal notation
 *@my_arg: arguments
 *@buffer: Buffer array to handle print
 *@flags: Calculates active flags
 *@width: get width
 *@precision: Precision specification
 *@size: Size specifier
 *Return: integer
 */
int print_X(va_list my_arg, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hex(my_arg, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**
 *print_hex - prints hexadecimal numbers
 *@my_arg: arguments
 *@check: an array
 *@buffer: Buffer array to handle print
 *@flags: Calculates active flags
 *@flag_s: Calculates active flags
 *@width: get width
 *@precision: Precision specification
 *@size: Size specifier
 * Return: integer
 */
int print_hex(va_list my_arg, char check[], char buffer[],
	int flags, char flag_s, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int number = va_arg(my_arg, unsigned long int);
	unsigned long int my_number = number;

	UNUSED(width);

	number = convert_u(number, size);

	if (number == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buffer[i--] = check[number % 16];
		number /= 16;
	}
	if (flags & F_HASH && my_number != 0)
	{
		buffer[i--] = flag_s;
		buffer[i--] = '0';
	}
	i++;
	return (write_un(0, i, buffer, flags, width, precision, size));
}
