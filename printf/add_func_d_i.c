#include "ft_printf.h"

int	handle_width_with_minus(t_flags *flagi)
{
	int	len;

	len = 0;
	while (flagi->width > 0)
	{
		ft_putchar(' ');
		flagi->width--;
		len++;
	}
	return (len);
}

static int	acc_more_than_strlen(t_flags *flagi, int str_len)
{
	int	len;

	len = 0;
	while (str_len < flagi->accuracy)
	{
		ft_putchar('0');
		str_len++;
		len++;
	}
	return (len);
}

int	putstr_for_minus(t_flags *flagi, char *str, int str_len, int nb)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (nb < 0)
	{
		ft_putchar('-');
		len++;
	}
	if (flagi->accuracy > str_len)
		len = len + acc_more_than_strlen(flagi, str_len);
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
		len++;
	}
	flagi->width -= len;
	len = len + handle_width_with_minus(flagi);
	return (len);
}

int	handle_minus(char *str, t_flags *flagi, int nb)
{
	int	len;
	int	str_len;

	str_len = ft_strlen(str);
	len = 0;
	flagi->zero = 0;
	len = len + putstr_for_minus(flagi, str, str_len, nb);
	return (len);
}
