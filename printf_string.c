#include "main.h"
/**
 * printf_string - print a string.
 * @val: argumen t.
 * Return: the length of the string.
 */

int printf_string(va_list val)
{
	char *s;
	int i, length;

	s = va_arg(val, char *s);
	if (s == NULL)
	{
		s = "(null)";
		length = _strlen(s);
			for (i = 0; i < length; i++)
				_putchar(s[i]);
		return (len);
	}
	else
	{
		length = _strlen(s);
		for (i = 0; i < length; i++)
			_putchar(s[i]);
		return (length);
	}
}
