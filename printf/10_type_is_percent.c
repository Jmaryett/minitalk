#include "ft_printf.h"

static int	per_putstr_no_minus(t_flags *flagi, char *str, int str_len)
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

static int	per_min_acc_no(t_flags *flagi, char *str, int str_len, int len)
{
	if (flagi->accuracy < str_len)
		flagi->accuracy = str_len;
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
	len = len + putstr_for_minus(flagi, str, str_len, 0);
	return (len);
}

static int	per_no_minus_no_acc(t_flags *flagi, int str_len, int len)
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

static int	per_handle_no_minus(char *str, t_flags *flagi)
{
	int	len;
	int	str_len;

	len = 0;
	str_len = ft_strlen(str);
	if (flagi->accuracy >= 0)
	{
		flagi->zero = 0;
		len = per_min_acc_no(flagi, str, str_len, len);
	}
	else if (flagi->accuracy < 0)
	{
		len = per_no_minus_no_acc(flagi, str_len, len);
		len = len + per_putstr_no_minus(flagi, str, str_len);
	}
	return (len);
}

int	process_percent(t_flags *flagi)
{
	int		len;

	len = 0;
	if (flagi->minus == 1)
		len = len + minus_one("%", flagi);
	else if (flagi->minus == 0)
		len = len + per_handle_no_minus("%", flagi);
	return (len);
}
