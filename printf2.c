#include "main.h"


/**
 * print_number - prints an integer
 * @n: The integer to print
 */
static void print_number(int n)
{
    unsigned int i;

    if (n < 0)
    {
        putchar('-');
        i = -n;
    }
    else
    {
        i = n;
    }

    if (i >= 10)
    {
        print_number(i / 10);
    }

    putchar(i % 10 + '0');
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
                case 'i':
                {
                    int d = va_arg(args, int);
                    print_number(d);
                    n++;
                    break;
                }
                default:
                    putchar('%');
                    putchar(*format);
                    n += 2;
                    break;
            }
        }
        else
        {
            putchar(*format);
            n++;
        }

        format++;
    }

    va_end(args);
    return (n);
}
