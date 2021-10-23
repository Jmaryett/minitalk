#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	my_putstr(char *s, t_flags *flagi)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	if (flagi->accuracy < 0)
	{
		while (s[i])
		{
			write(1, &s[i], 1);
			i++;
			len++;
		}
		return (len);
	}
	while (s[i] && i < flagi->accuracy)
	{
		write(1, &s[i], 1);
		i++;
		len++;
	}
	return (len);
}

static int	my_putstr_for_p(char *s, t_flags *flagi)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	if (flagi->accuracy <= 0)
	{
		while (s[i])
		{
			write(1, &s[i], 1);
			i++;
			len++;
		}
		return (len);
	}
	while (s[i] && i < flagi->accuracy)
	{
		write(1, &s[i], 1);
		i++;
		len++;
	}
	return (len);
}

int	no_ad_acc_minus_p(char *str, t_flags *flagi, int str_len, int len)
{
	int	i;
	int	len_output;

	i = -1;
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

int	no_add_acc_with_min(char *str, t_flags *flagi)
{
	int	len;

	len = ft_strlen(str);
	if (flagi->accuracy > 0)
	{
		len = my_putstr_for_p(str, flagi);
		while (len < flagi->width)
		{
			ft_putchar(' ');
			len++;
		}
		return (len);
	}
	else
	{
		len = 0 + my_putstr_for_p(str, flagi);
		while (len < flagi->width)
		{
			ft_putchar(' ');
			len++;
		}
	}
	return (len);
}
