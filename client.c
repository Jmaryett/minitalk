#include "client.h"

void	converting_to_bits(char c, int pid)
{
	int	i;

	i = 128;
	while(i >= 1)
	{
		if (i & c)
		{
			if (kill(pid, SIGUSR1) == -1)
				errors("Error signal!");
			ft_putnbr_fd(1, 1);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				errors("Error signal!");
			ft_putnbr_fd(0, 1);
		}
		i /= 2;
	}
	usleep(100);
}

void	send_str(int pid, char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		converting_to_bits(s[i], pid);
		write (1, "\n", 1);
		i++;
	}
	return ;
}

/* void	ft_handler(int signum, siginfo_t *siginfo, void *context)
{
	(void)context;
	(void)siginfo;
	(void)signum;
	ft_putstr_fd("Signal recieved\n", 1);
} */

int	main(int argc, char **argv)
{
/* 	struct sigaction	sigac;

  	sigac.sa_flags = SA_SIGINFO;
	sigac.sa_sigaction = ft_handler;
	if (sigaction(SIGUSR2, &sigac, NULL) == -1)
		errors("Error in sigaction"); */
	if (argc != 3)
		errors("Wrong arguments");
	send_str(atoi(argv[1]), argv[2]);
/* 	while (1)
		pause (); */
	return (0);
}
