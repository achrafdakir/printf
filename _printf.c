#include "main.h"

/**
 * print_string_and_increment_count - helper function
 * @str: input
 * @count: input
 * Return: a pointer to the string
 */

static int print_string_and_increment_count(const char *str, int *count)
{
	while (*str != '\0')
	{
		putchar(*str);
		(*count)++;
		str++;
		return (*str);
	}

	if (str == NULL)

	{
		return (-1);
	}
}

/**
 * print_char_and_increment_count - helper function
 * @c: input
 * @count: input
 * Return: the character
 */

static void print_char_and_increment_count(char c, int *count)
{
	if (c != '\0')
	{
		putchar(c);
		(*count)++;
		return (c);
	}
	else
		return (-1);
}

/**
 * _printf - our function Printf
 * @format: the format string
 * @...: arguments
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);
	if (format == NULL)
		return (-1);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				char c = va_arg(args, int);

				print_char_and_increment_count(c, &count);
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);

				print_string_and_increment_count(str, &count);
			}
			else if (*format == '%')
				print_char_and_increment_count('%', &count);
			else
			{
				print_char_and_increment_count('%', &count);
				print_char_and_increment_count(*format, &count);
			}
		}
		else
			print_char_and_increment_count(*format, &count);
		format++;
	}
	va_end(args);
	return (count);
}
