#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

void print_buffer(char buffer[], int *buff_ind);
int _printf(const char *format, ...);
int print_int(va_list my_list, char buffer[],
		int flags, int width, int precision, int size);
int print_binary(va_list b_list, char buffer[],
		int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
		int flags, int width, int precision, int size);
long int convert_size_number(long int num, int size);

#endif
