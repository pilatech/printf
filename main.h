#ifndef _PRINTF_FILE_
#define _PRINTF_FILE_
#include <stdarg.h>

int _printf(const char *format, ...);
int (*process_format(char))(va_list args);
int character(va_list);
int string(va_list);
void print_char(int *counter, int *i, int inc, const char *format);
/**
 * struct format - format structure.
 *	@type: format specifier.
 *	@op: the function to run.
 */
typedef struct format
{
	char type;
	int (*op)(va_list);
} format_t;

#endif
