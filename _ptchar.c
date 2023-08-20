#include "main.h"
/**
 *_ptchar - prints character
 *@c: the input to be printed
 *Return: (1)
 */
int _ptchar(char c)
{
	return (write(1, &c, 1));
}
