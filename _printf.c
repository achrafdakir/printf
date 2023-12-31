#include "main.h"

/**
 * print_string_and_increment_count - helper function
 * @str: input
 * @count: input
 */

static void print_string_and_increment_count(char *str, int *count)
{
	if (str == NULL)
	{
		str = "(null)";
	}
	while (*str != '\0')
	{
		_putchar(*str);
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
	_putchar(c);
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
	int count = 0;
	va_list args;

	va_start(args, format);
	if (!format || !format[0] || (*format == '%' && *(format + 1) == '\0'))
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
			else if (*format == 'd' || *format == 'i')
				count += print_number(va_arg(args, int));
			else if (*format == 'b')
				print_binary(va_arg(args, unsigned int), &count);
			else
			{
					print_char_and_increment_count('%', &count);
					print_char_and_increment_count(*format, &count);
			}
		}
		else
			print_char_and_increment_count(*format, &count);
		format++;
	} va_end(args);
	return (count);
}
