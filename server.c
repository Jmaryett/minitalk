/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:41:03 by jmaryett          #+#    #+#             */
/*   Updated: 2021/11/18 19:55:42 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sv_handler(int signum, siginfo_t *siginfo, void *unused)
{
	static int	ascii = 0;
	static int	power = 0;

	(void)unused;
	if (signum == SIGUSR1)
		ascii += (128 >> power);
	power += 1;
	if (power == 8)
	{
		ft_putchar(ascii);
		power = 0;
		ascii = 0;
	}
	if (siginfo->si_pid <= 0)
		errors("\nServer didn't get client's PID!\n");
	if (kill(siginfo->si_pid, SIGUSR2) == -1)
		errors("Error in returning signal!\n");
}

int	main(int argc, char **argv)
{
	struct sigaction	sigac;

	(void)argv;
	if (argc != 1)
		errors("Error arguments\n");
	write(1, "Server started!\nPID: ", 21);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	sigac.sa_flags = SA_SIGINFO;
	sigac.sa_sigaction = sv_handler;
	if ((sigaction(SIGUSR1, &sigac, 0)) == -1)
		errors("Error sigaction\n");
	if ((sigaction(SIGUSR2, &sigac, 0)) == -1)
		errors("Error sigaction\n");
	while (1)
		pause();
	return (0);
}
