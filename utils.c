/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 19:55:50 by jmaryett          #+#    #+#             */
/*   Updated: 2021/11/18 19:55:51 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static	unsigned long	attoi(char *str)
{
	unsigned long	n;

	n = 0;
	while (*str >= '0' && *str <= '9')
	{
		n = n * 10 + (*str - '0');
		str++;
	}
	return (n);
}

int	ft_atoi(const char *str)
{
	int				count;
	unsigned long	n;

	n = 0;
	count = 1;
	while (*str == ' ' || (*str >= 7 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			count = -1;
		str++;
	}
	if (*str < '0' || *str > '9')
		return (0);
	n = attoi((char *)str);
	if (n > 9223372036854775807 && count == 1)
		return (-1);
	if (n > 9223372036854775807 && count == -1)
		return (0);
	return (count * n);
}

void	errors(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	exit (1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n == -2147483647 - 1)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	else if (n == 2147483647)
	{
		write(1, "2147483647", 10);
		return ;
	}
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n);
		return ;
	}
	else if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar(((n % 10) + '0'));
}
