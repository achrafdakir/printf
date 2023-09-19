#include "main.h"
/**
 * printf_char - print a character
 * @val: the arguments
 * Return: 1
 */
int printf_char(va_list val)
{
	char s;

	s = va_arg(val, int);
	putchar(s);
	return (1);
}
