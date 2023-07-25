#include <unistd.h>
#include "main.h"

/**
 *	print_char - prints character and increments counter and index.
 *	@counter: the number of already printed characters.
 *	@i: the current format index.
 *	@inc: amount to increment the index with.
 *	@format: the format string.
 *
 *	Return: nothing
 */

void print_char(int *counter, int *i, int inc, const char *format)
{
	int printed;

	printed = write(1, &format[*i], 1);
	*counter = *counter + printed;
	*i = *i + inc;
}
