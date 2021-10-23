#include "ft_printf.h"

int	handle_no_minus(char *str, t_flags *flagi, int str_len, int len)
{
	int	i;
	int	len_output;

	i = -1;
	if (flagi->accuracy < str_len && flagi->accuracy > -1)
		len_output = flagi->accuracy;
	else
		len_output = str_len;
	if (flagi->width > len_output)
	{	
		flagi->width -= len_output;
		while (++i < flagi->width)
		{
			ft_putchar(' ');
			len++;
		}
	}
	i = -1;
	while (++i < len_output)
	{
		ft_putchar(str[i]);
		len++;
	}
	return (len);
}

int	minus_one(char *str, t_flags *flagi)
{
	int	len;

	len = ft_strlen(str);
	if (flagi->accuracy >= 0)
	{
		len = my_putstr(str, flagi);
		while (len < flagi->width)
		{
			ft_putchar(' ');
			len++;
		}
		return (len);
	}
	else
	{
		len = 0 + my_putstr(str, flagi);
		while (len < flagi->width)
		{
			ft_putchar(' ');
			len++;
		}
	}
	return (len);
}

int	process_string(char *str, t_flags *flagi)
{
	int	len;
	int	str_len;

	len = 0;
	if (!str)
		str = "(null)";
	str_len = ft_strlen(str);
	if (flagi->accuracy >= 0 && flagi->accuracy > str_len)
		flagi->accuracy = str_len;
	if (flagi->minus == 1)
		len = len + minus_one(str, flagi);
	else
		len = len + handle_no_minus(str, flagi, str_len, len);
	return (len);
}
