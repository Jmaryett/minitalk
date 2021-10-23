#include "ft_printf.h"

static int	type_hexa_thx_norms(char type, t_flags *flagi, va_list arg)
{
	int	len;
	int	capitals;

	len = 0;
	if (type == 'x')
	{	
		capitals = 0;
		len = process_hexa(va_arg(arg, unsigned int), flagi, capitals);
	}
	if (type == 'X')
	{
		capitals = 1;
		len = process_hexa(va_arg(arg, unsigned int), flagi, capitals);
	}
	return (len);
}

static int	type_c_thx_norms(t_flags *flagi, va_list arg)
{
	int		len;
	char	c;

	len = 0;
	c = va_arg(arg, int);
	len = process_char(c, flagi);
	return (len);
}

int	process_types(char type, t_flags *flagi, va_list arg)
{
	int	len;

	len = 0;
	if (type == 'c')
		len = type_c_thx_norms(flagi, arg);
	if (type == 's')
		len = process_string(va_arg(arg, char *), flagi);
	if (type == 'p')
		len = process_pointer(va_arg(arg, unsigned long), flagi);
	if (type == 'd' || type == 'i')
		len = process_integer(va_arg(arg, int), flagi);
	if (type == 'u')
		len = process_uns_int(va_arg(arg, unsigned int), flagi);
	if (type == 'x' || type == 'X')
		len = type_hexa_thx_norms(type, flagi, arg);
	if (type == '%')
		len = process_percent(flagi);
	return (len);
}
