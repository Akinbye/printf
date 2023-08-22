#ifndef _MAIN_H_
#define _MAIN_H_

#define BUFSIZE 1024
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

#define S_LONG 2
#define S_SHORT 1

struct format
{
	char format;
	int (*fn)(va_list, char[], int, int, int, int);
};
typedef struct format format_t;
void print_buff(char buffer[], int *buff_ind);
int handle_p(const char *format, int *ind, va_list my_list, char buffer[],
		int flags, int width, int precision, int size);

int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

int _printf(const char *format, ...);
int printf_int(const char *format, ...);
int print_c(va_list my_arg, char buffer[],
		int flags, int width, int precision, int size);
int print_s(va_list my_arg, char buffer[],
	int flags, int width, int precision, int size);
int print_per(va_list my_arg, char buffer[],
	int flags, int width, int precision, int size);
int print_i(va_list my_arg, char buffer[],
	int flags, int width, int precision, int size);
int print_b(va_list my_arg, char buffer[],
	int flags, int width, int precision, int size);
int print_u(va_list my_arg, char buffer[],
	int flags, int width, int precision, int size);
int print_o(va_list my_arg, char buffer[],
	int flags, int width, int precision, int size);
int print_x(va_list my_arg, char buffer[],
	int flags, int width, int precision, int size);
int print_X(va_list my_arg, char buffer[],
	int flags, int width, int precision, int size);
int print_p(va_list my_arg, char buffer[],
	int flags, int width, int precision, int size);
int print_non(va_list my_arg, char buffer[],
	int flags, int width, int precision, int size);
int print_r(va_list my_arg, char buffer[],
	int flags, int width, int precision, int size);
int print_rot(va_list my_arg, char buffer[],
	int flags, int width, int precision, int size);

int handle_w(char c, char buffer[], int flags, int width,
		int precision, int size);
int write_n(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int write_p(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);
int write_un(int is_negative, int ind,char buffer[],
		int flags, int width, int precision, int size);

int printable(char);
int append(char, char[], int);
int is_digit(char);
long int convert_s(long int number, int size);
long int convert_u(unsigned long int number, int size);

#endif /* MAIN_H */
