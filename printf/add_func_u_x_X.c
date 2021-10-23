#include "ft_printf.h"

int	u_handle_width_with_minus(t_flags *flagi)
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

static int	u_acc_more_than_strlen(t_flags *flagi, int str_len)
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

int	u_putstr_for_minus(t_flags *flagi, char *str, int str_len)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (flagi->accuracy > str_len)
		len = len + u_acc_more_than_strlen(flagi, str_len);
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
		len++;
	}
	flagi->width -= len;
	len = len + u_handle_width_with_minus(flagi);
	return (len);
}

int	u_handle_minus(char *str, t_flags *flagi)
{
	int	len;
	int	str_len;

	len = 0;
	str_len = ft_strlen(str);
	flagi->zero = 0;
	len = len + u_putstr_for_minus(flagi, str, str_len);
	return (len);
}
