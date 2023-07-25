#include <stddef.h>
#include "main.h"

/**
 * process_format - process the format string.
 * @incoming_char: the format specifier.
 *
 * Return: number of printed characters.
 */
int (*process_format(char incoming_char))(va_list)
{
	int i;

	format_t array[] = {
		{'c', character},
		{'s', string},
		{'\0', NULL}
	};
	i = 0;
	while (array[i].type != '\0')
	{
		if (incoming_char == array[i].type)
			return (array[i].op);
		i++;
	}
	return (NULL);
}
