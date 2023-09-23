#include "main.h"
/**
 * print_binary_and_increment_count - helper function
 * @n: the unsigned int to print as binary
 * @count: pointer to count the characters printed
 */
void print_binary(unsigned int n, int *count)
{

	if (n == 0)
	{
		 _putchar('0');
		(*count)++;
	}
	else
	{
		char binary[32];
		int i = 0;

		while (n > 0)
		{
			binary[i] = (n % 2) + '0';
			n /= 2;
			i++;
		}

		for (i = i - 1; i >= 0; i--)
		{
			_putchar(binary[i]);
			(*count)++;
		}
	}
}

