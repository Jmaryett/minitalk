#include "ft_printf.h"

int	u_putstr_no_minus(t_flags *flagi, char *str, int str_len)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	if (flagi->accuracy > str_len)
	{
		while (str_len < flagi->accuracy)
		{
			ft_putchar('0');
			str_len++;
			len++;
		}
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
		len++;
	}
	return (len);
}

int	u_no_min_wid_with_ac(t_flags *flagi, char *str, int str_len, int len)
{
	if (flagi->accuracy < str_len)
		flagi->accuracy = str_len;
	flagi->width -= flagi->accuracy;
	while (flagi->width > 0)
	{
		if (flagi->zero == 1)
		{
			ft_putchar('0');
			flagi->width--;
			len++;
		}
		else if (flagi->zero == 0)
		{
			ft_putchar(' ');
			flagi->width--;
			len++;
		}
	}
	len = len + u_putstr_for_minus(flagi, str, str_len);
	return (len);
}

int	u_no_minus_no_acc(t_flags *flagi, int str_len, int len)
{
	while (str_len < flagi->width)
	{
		if (flagi->zero == 1)
		{
			ft_putchar('0');
			str_len++;
			len++;
		}
		else if (flagi->zero == 0)
		{
			ft_putchar(' ');
			str_len++;
			len++;
		}
	}
	return (len);
}
