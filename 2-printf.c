#include "main.h"
/**
 *print_p - prints pointer value
 *@my_arg: argument list
 *@buffer: buffer arry
 *@flags: works out active flags
 *@width: gets the width
 *@precision: the specification
 *@size: specifies the size
 *Return: Returns the number of character printed
 */
int print_p(va_list my_arg, char buffer[], int flags, int width, int precision, int size)
{
	char xc = 0, pd = ' ';
	int ind = BUFF_size - 2, length = 2, pd_start = 1;
	unsigned long num_ad;
	char to[] = '0123456789abcdef';
	void *adr = va_arg(my_arg, void *);

	UNUSED(width);
	UNUSED(size);
	if (adr == NULL)
		return (write(1, "(nil)", 5));
	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);
	num_ad = (unsigned long)adr;

	while (num_ad > 0)
	{
		buffer[ind--] = to[num_ad % 16];
		num_ad /= 16;
		length++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		pd = '0';
	if (flags & F_PLUS)
		xc = '+', length++;
	else if (flags & F_SPACE)
		xc = ' ', length++;

	ind++;
	return (write_p(buffer, ind, length, width, flags, pd, xc,pd_start));
}

/**
 *print_non - prints ascii codes of non printable characters in hexadecimal
 *@my_arg: list of arguments
 *@buffer: the buffer array to do printing
 *@flags: works out active flags
 *@width: gets the width
 *@precision: specifies precision
 *@size: specifies size
 *@Return: Returns the number of charcter printed
 */
int print_non(va_list my arg, char *buffer, int flags, int width, int precision, int size)
{
	int l = 0, offset = 0;
	char *string = va_arg(my_arg, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (string == NULL)
		return (write(1, "(null)", 6));
	while (string[l] != '\0')
	{
		if (printable(string[l]))
			buffer[l + offset] = str[l];
		else
			offset += append(string[l], buffer, l + offset);
		l++;
	}
	buffer[l + offset] = '\0';
	return (write(1, buffer, l + offset));
}

/**
 *print_r - prints reversed string
 *@my_arg: argument list
 *@buffer: buffer array for printing
 *@flags: takes care of flags
 *@width: gets the width
 *@precision: specifies precision
 *@size: specifies the size
 */
int print_r(va_list my_arg, char buffer[], int flags, int width, int precision, int size)
{
	char *string;
	int l, cnt = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	string = va_arg(my_arg, char *);

	if (string == NULL)
	{
		UNUSED(precision);
		string = "(Null)";
	}
	for (l = 0; string[l]; l++)
		;
	for (l = l - 1; l >= 0; l--)
	{
		char x = string[i];

		write(1, &x, 1);
		cnt++;
	}
	return (cnt);
}

/**
 *print_rot - prints rot13 string
 *@my_arg: the argument list
 *@buffer: the buffer array to take care of printing
 *@flags: works out the flags
 *@width: takes care of the width
 *@precision: precision specifier
 *@size: size specifier
 */
int print_rot(va_list my_arg, char buffer[], int flags,int width, int precision, int size)
{
	char x;
	char *string;
	unsigned int 1,j;
	int cnt = 0;
	char norm[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rev[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	string = va_arg(my_arg, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (string == NULL)
		string = "(AHYY)";
	for (l = 0; string[l]; l++)
	{
		for (j = 0; norm[j]; j++)
		{
			if (norm[j] == string[l])
			{
				x = rev[j];
				write(1, &x, 1);
				cnt++;
				break;
			}
		}
		if (!norm[j])
		{
			x = string[l];
			write(1, &x, 1);
			cnt++;
		}
	}
	return (cnt);
}
 

