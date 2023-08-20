#include "main.h"
/**
 *put_s - to print character array
 *@c: the string holder
 *Return: Returns the number of bytes
 */

int put_s(char *c)
{
	int cnt = 0;
	if (c)
	{
		for (cnt = 0; c[cnt] != '\0'; cnt++)
		{
			_ptchar(c[cnt]);
		}
	}
	return (cnt);
}
