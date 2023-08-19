#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

int _printf(const char *format, ...);
int print_int(va_list my_list, char buffer[]);
int print_binary(va_list b_list, char buffer[]);


#endif
