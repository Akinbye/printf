#ifndef _MAIN_H_
#define _MAIN_H_

#define BUFSIZE 1024
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

void print_buffer(char buffer[], int *buff_ind);
void handle_conversion(char specifier, va_list my_list);
int _ptchar(char c);
int _printf(const char *format, ...);
int put_s(char *c);
int printf_int(const char *format, ...);

#endif
