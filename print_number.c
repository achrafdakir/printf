#include "main.h"
/**
 * length - the length of a number
 * @number: input integer
 * Return: length of number
 */
int length(int number)
{
	int count = 0;

	if (number == 0)
		return (1);

	while (number != 0)
	{
		number = number / 10;
		count++;
	}

	return (count);
}

/**
 * print_number - print numbers
 * @number: an integer
 * Return: an integer printed
 */
int print_number(long int number)
{
	int p = 0;

	if (number == 0)
	{
		_putchar('0');
		return (1);
	}

	if (number < 0)
	{
		p++;
		_putchar('-');
		number = -number;
	}

	p += length(number);

	if (number >= 10)
	{
		print_number(number / 10);
		print_number(number % 10);
	} else
	{
		_putchar(number + '0');
	}
	return (p);

}
