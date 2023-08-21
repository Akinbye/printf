#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

void handle_conversion(const char *format, va_list my_list);
int _ptchar(char c);
int _printf(const char *format, ...);
int put_s(char *c);
int printf_int(const char *format, ...);

#endif
