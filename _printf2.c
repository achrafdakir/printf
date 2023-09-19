#include "main.h"
/**
 * print_number - prints an integer
 * @format: the format string
 * @n: the integer
 * Return: the integer
 */
static int print_number(const char *format, int n)
{
	unsigned int i;

	if (n < 0)
	{
		i = (-1 * n);
	}
	else
	{
		i = n;
	}
	return (n);
}


/**
 * _printf - Our custom printf function.
 * @format: The format string
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	int n = 0;
	va_list args;

	va_start(args, format);
	if (format == NULL)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'd':
					{
						int d = va_arg(args, int);

						print_number(d, &n);
					}
					break;
				case 'i':
					{
						int i = va_arg(args, int);

						print_number(i, &n);
					}
					break;
				default:
					print_number('%', &n);
					print_number(*format, &n);
					break;
			}
		} else
		{
			print_number(*format, &n);
		}
		format++;
	}
	va_end(args);
	return (n);
}
