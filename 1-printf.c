#include "main.h"
/**
 *print_int - prints integers
 *@my_list: all arguments
 *@buffer: array for print
 *Return: 0
 */
int print_int(va_list my_list, char buffer[])
{
	int m = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(my_list, long int);
	unsigned long int val;

	n = 0;

	if (n == 0)
		buffer[m--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	val = (unsigned long int)n;

	if (n < 0)
	{
		val = (unsigned long int)((-1) * n);
		is_negative = 1;
	}
	while (val > 0)
	{
		buffer[m--] = (val % 10) + '0';
		val /= 10;
	}
	m++;
	return (is_negative, m, *buffer);
}
/**
 *print_binary - prints i
 *@b_list: arguments
 *@buffer: an array
 *Return: 0
 */
int print_binary(va_list b_list, char buffer[])
{
	unsigned int z, b, c, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);

	z = va_arg(b_list, unsigned int);
	b = 2147483648;
	a[0] = z / b;

	for (c = 1; c < 32; c++)
	{
		b /= 2;
		a[c] = (z / b) % 2;
	}
	for (c = 0, sum = 0, count = 0; c < 32; c++)
	{
		sum += a[c];
		if (sum || c == 31)
		{
			char y = '0' + a[c];

			write(1, &y, 1);
			count++;
		}
	}
	return (count);
}
