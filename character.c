#include <unistd.h>
#include <stdarg.h>

/**
 * character - print character.
 * @args: the variadic argument.
 *
 * Return: Number of printed characters.
 */
int character(va_list args)
{
	char str[2];
	int x;
	int i;

	x = va_arg(args, int);
	str[0] = x;
	str[1] = '\0';

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}

	return (i);
}
