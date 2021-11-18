/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:41:12 by jmaryett          #+#    #+#             */
/*   Updated: 2021/11/18 19:55:36 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "stdio.h"

void	sending_bits(char c, int pid)
{
	int	i;

	i = 128;
	while (i >= 1)
	{
		if (i & c)
		{
			if (kill(pid, SIGUSR1) == -1)
				errors("Error in sending signal!\n");
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				errors("Error in sending signal!\n");
		}
		i /= 2;
		usleep(1000);
	}
}

int	send_str(int pid, char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		sending_bits(s[i], pid);
		i++;
	}
	exit (0);
	return (0);
}

void	cl_handler(int signum, siginfo_t *siginfo, void *context)
{
	(void)context;
	(void)siginfo;
	(void)signum;
	write(1, "Recieved signal from server\n", 28);
	return ;
}

int	main(int argc, char **argv)
{
	struct sigaction	sigac;

	if (argc != 3)
		errors("Wrong arguments!\n");
	sigac.sa_flags = SA_SIGINFO;
	sigac.sa_sigaction = cl_handler;
	if (sigaction(SIGUSR2, &sigac, NULL) == -1)
		errors("Error in client sigaction\n");
	if (ft_atoi(argv[1]) < 0)
		errors("Wrong PID!\n");
	send_str(ft_atoi(argv[1]), argv[2]);
	sleep(5);
	errors("Something went wrong!\n");
	return (0);
}
