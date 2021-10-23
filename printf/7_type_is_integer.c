#include "ft_printf.h"

int	putstr_no_minus(t_flags *flagi, char *str, int str_len)
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

int	no_minus_width_with_acc(t_flags *flagi, char *str, int nb, int str_len)
{
	int	len;

	len = 0;
	if (flagi->accuracy < str_len)
		flagi->accuracy = str_len;
	if (nb < 0)
		flagi->width -= (flagi->accuracy + 1);
	else if (nb >= 0)
		flagi->width -= flagi->accuracy;
	while (flagi->width-- > 0)
	{
		if (flagi->zero == 1)
		{
			ft_putchar('0');
			len++;
		}
		else if (flagi->zero == 0)
		{
			ft_putchar(' ');
			len++;
		}
	}
	len = len + putstr_for_minus(flagi, str, str_len, nb);
	return (len);
}

int	no_minus_no_acc(t_flags *flagi, int str_len, int nb, int len)
{
	if (flagi->zero == 1)
	{
		if (nb < 0)
			ft_putchar('-');
		while (str_len++ < flagi->width)
		{
			ft_putchar('0');
			len++;
		}
	}
	else if (flagi->zero == 0)
	{
		while (str_len++ < flagi->width)
		{
			ft_putchar(' ');
			len++;
		}
		if (nb < 0)
			ft_putchar('-');
	}
	return (len);
}

int	handle_no_minus_int(t_flags *flagi, char *str, int nb)
{
	int	len;
	int	str_len;

	len = 0;
	str_len = ft_strlen(str);
	if (flagi->accuracy >= 0)
	{
		flagi->zero = 0;
		len = len + no_minus_width_with_acc(flagi, str, nb, str_len);
	}
	else if (flagi->accuracy < 0)
	{
		if (nb < 0)
		{
			str_len++;
			len++;
		}
		len = no_minus_no_acc(flagi, str_len, nb, len);
		len = len + putstr_no_minus(flagi, str, str_len);
	}
	return (len);
}

int	process_integer(int nb, t_flags *flagi)
{
	int		len;
	char	*str;
	int		nb2;

	nb2 = nb;
	len = 0;
	if (nb == 0 && flagi->accuracy == 0)
	{
		str = ft_strdup("");
		len = handle_width_with_minus(flagi);
		len = len + putstr_for_minus(flagi, str, ft_strlen(str), nb2);
		free(str);
		return (len);
	}
	if (nb < 0 && nb != -2147483648)
		nb *= -1;
	str = ft_itoa(nb);
	if (flagi->minus == 1)
		len = len + handle_minus(str, flagi, nb2);
	else if (flagi->minus == 0)
		len = len + handle_no_minus_int(flagi, str, nb2);
	free(str);
	return (len);
}
