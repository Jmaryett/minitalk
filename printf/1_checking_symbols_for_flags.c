#include "ft_printf.h"

int	check_digit(char *format, int i)
{
	if (format[i] >= '1' && format[i] <= '9')
		return (1);
	return (0);
}

int	check_type(char *format, int i)
{
	if (format[i] == 'c' || format[i] == 'p' || format[i] == 'i'
		|| format[i] == 's' || format[i] == 'd' || format[i] == 'u'
		|| format[i] == 'x' || format[i] == 'X' || format[i] == '%')
		return (1);
	return (0);
}

int	check_flag(char *format, int i)
{
	if (format[i] == '-' || format[i] == '0' || format[i] == '.'
		|| format[i] == '*')
		return (1);
	return (0);
}

int	check_next_char_after_zero(char *format, int i)
{
	if ((format[--i] >= '1' && format[--i] <= '9') || format[--i] == '-')
		return (0);
	return (1);
}
