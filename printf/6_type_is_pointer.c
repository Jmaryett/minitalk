#include "ft_printf.h"

static	char	*no_address(void)
{
	char	*s2;

	s2 = malloc(sizeof(char) * 2);
	if (!s2)
		return (NULL);
	s2[0] = '0';
	s2[1] = '\0';
	return (s2);
}

static char	*address_not_zero(unsigned long address, int count)
{
	char			*str;
	unsigned long	adr2;

	adr2 = address;
	while (address != 0)
	{
		address = address / 16;
		count++;
	}
	str = malloc(sizeof(char) * (count + 1));
	if (!str)
		return (NULL);
	str[count] = '\0';
	count--;
	while (adr2 != 0)
	{
		if (adr2 % 16 < 10)
			str[count] = (adr2 % 16) + '0';
		else
			str[count] = (adr2 % 16) + 87;
		adr2 = adr2 / 16;
		count--;
	}
	return (str);
}

static int	no_accuracy(char *str, t_flags *flagi)
{
	int	len;

	len = 0;
	if (flagi->minus == 1)
		len = len + minus_one(str, flagi);
	else
		len = len + handle_no_minus(str, flagi, ft_strlen(str), len);
	return (len);
}

static int	ad_acc_nul(t_flags *flagi)
{
	char	*str;
	int		len;

	len = 0;
	str = ft_strdup("0x");
	if (flagi->minus == 1)
		len = len + no_add_acc_with_min(str, flagi);
	else if (flagi->minus == 0)
		len = len + no_ad_acc_minus_p(str, flagi, 2, len);
	free (str);
	return (len);
}

int	process_pointer(unsigned long address, t_flags *flagi)
{
	int		final_len;
	int		count;
	char	*str;

	final_len = 0;
	count = 0;
	if (address == 0 && flagi->accuracy == 0)
	{
		final_len = final_len + ad_acc_nul(flagi);
		return (final_len);
	}
	else if (address == 0 && flagi->accuracy != 0)
		str = no_address();
	else
		str = address_not_zero(address, count);
	count = 0;
	str = ft_strjoin("0x", str);
	final_len = final_len + no_accuracy(str, flagi);
	free (str);
	return (final_len);
}
