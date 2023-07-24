#include <unistd.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * _printf - print characters in a formated string.
 * @format: the format string.
 *
 * Return: Number of printed characters.
 */
int _printf(const char *format, ...)
{
	int counter, i, printed;
	va_list args;

	counter = i = printed = 0;
	va_start(args, format);
	if (format == NULL)
		return (-1);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			print_char(&counter, &i, 1, format);
			continue;
		}
		else
		{
			if (format[i + 1] == 'c' || format[i + 1] == 's')
			{
				if (process_format(format[i + 1]))
				{
					counter += process_format(format[i + 1])(args);
					i = i + 2;
					continue;
				}
				else
				{
					counter += write(1, &format[i], 1);
					continue;
				}
			}
			else if (format[i + 1] == '%')
			{
				print_char(&counter, &i, 2, format);
				continue;
			}
			print_char(&counter, &i, 1, format);
		}
	}
	va_end(args);
	return (counter);
}
