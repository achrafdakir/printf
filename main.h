#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>


int _printf(const char *format, ...);
int _putchar(char c);
int print_number(long int number);
void print_binary(int n, int *count);


#endif
