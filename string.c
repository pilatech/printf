#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stddef.h>

/**
 * string - print the string.
 * @args: the variadic arguments.
 *
 * Return: number of printed characters.
 */
int string(va_list args)
{
	char *str;
	int x;
	int counted;

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";
	x = 0;
	counted = 0;
	while (str[x] != '\0')
	{
		write(1, &str[x], 1);
		x++;
		counted++;
	}
	return (counted);
}
