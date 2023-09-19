#include "main.h"

/**
 * print_string_and_increment_count - helper function
 * @str: input
 * @count: input
 */

static void print_string_and_increment_count(const char *str, int *count)
{
	while (*str != '\0')
	{
		putchar(*str);
		(*count)++;
		str++;
	}
}

/**
 * print_char_and_increment_count - helper function
 * @c: input
 * @count: input
 */

static void print_char_and_increment_count(char c, int *count)
{
	putchar(c);
	(*count)++;
}

/**
 * _printf - our function Printf
 * @format: the format string
 * @...: arguments
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int count;
	va_list args;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			formart++;
			switch (*format)
			{
				case 'c':
				{
					char c = va_arg(args, int);

					print_char_and_increment_count(c, &count);
				}
				break;
				case 's':
				{
					char *str = va_arg(args, char *);

					print_string_and_increment_count(str, &count);
				}
				break;
				case '%':
					print_char_and_increment_count('%', &count);
					break;
				default:
					print_char_and_increment_count('%', &count);
					print_char_and_increment_count(*format, &count)
					break;
			}
		}
		else
			print_char_and_increment_count(*format, &count);
		format++;
	}
	va_end(args);
	return (count);
}
