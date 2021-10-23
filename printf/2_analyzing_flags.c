#include "ft_printf.h"

int	we_met_zero(char *format, int i, t_flags *flagi)
{
	if (!check_next_char_after_zero(format, i))
		return (i);
	flagi->zero = 1;
	return (i);
}

void	analyze_minus(t_flags *flagi)
{
	flagi->minus = 1;
	flagi->zero = 0;
}

int	analyze_accuracy(char *format, int i, t_flags *flagi, va_list arg)
{
	i++;
	if (format[i] == '*')
	{
		flagi->accuracy = va_arg(arg, int);
		i++;
		return (i);
	}
	flagi->accuracy = 0;
	while (format[i] >= '0' && format[i] <= '9')
	{
		flagi->accuracy = flagi->accuracy * 10 + ((format[i]) - '0');
		i++;
	}
	return (i);
}

void	analyze_width(va_list arg, t_flags *flagi)
{
	flagi->star = 1;
	flagi->width = va_arg(arg, int);
	if (flagi->width < 0)
	{
		flagi->minus = 1;
		flagi->width = flagi->width * (-1);
		flagi->zero = 0;
	}
}

void	analyze_width_2(char c, t_flags *flagi)
{
	if (flagi->star == 1)
		flagi->width = 0;
	flagi->width = flagi->width * 10 + (c - '0');
}
