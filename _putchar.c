#include <unistd.h>
#include "main.h"
/**
 * _putchar - create _putchar
 * @c: the character to enter
 * Return: Success 1 Error -1
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}
