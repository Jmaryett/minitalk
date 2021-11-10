#include "minitalk.h"

/* void	ft_handler(int signum, siginfo_t *sig, void *context)
{
	static unsigned char	symb;
	static int				power;

	(void)context;
	(void)sig;
	symb = 0;
	power = 0;
	if (signum == SIGUSR1)
	{
		symb += ((unsigned char)128 >> power);
		//write(1, "1", 1);
	}
	else if (signum == SIGUSR2)
		write(1, "0", 1);
	power += 1;
	if (power == 8)
	{
		write(1, &symb, 1);
		//write (1, "\n", 1);
		power = 0;
		symb = 0;
 		if (kill(sig->si_pid, SIGUSR1) == -1)
			errors("Error in returned signal!\n");
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sigac;

	(void)argv;
	if (argc != 1)
		errors("Wrong arguments!\n");
	write(1, "Server started!\nPID: ", 21);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	sigac.sa_flags = SA_SIGINFO;
	sigac.sa_sigaction = ft_handler;
	if (sigaction(SIGUSR1, &sigac, 0) == -1)
		errors("Error in sigaction!\n");
	if (sigaction(SIGUSR2, &sigac, 0) == -1)
		errors("Error in sigaction!\n");
	while (1)
		pause();
	return (0);
} */

void	my_handler(int signum, siginfo_t *siginfo, void *unused)
{
	static int	ascii = 0;
	static int	power = 0;

	(void)unused;
	if (signum == SIGUSR1)
		ascii += 128 >> power;
	power += 1;
	if (power == 7)
	{
		ft_putchar(ascii);
		power = 0;
		ascii = 0;
		if (kill(siginfo->si_pid, SIGUSR1) == -1)
			errors("Error in returned signal\n");
	}
	else 
	{
		if (kill(siginfo->si_pid, SIGUSR2) == -1)
			errors("Error in returned signal\n");
	}
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
	sigemptyset(&sigac.sa_mask);
	sigac.sa_sigaction = my_handler;
	if ((sigaction(SIGUSR1, &sigac, 0)) == -1)
		errors("Error sigaction\n");
	if ((sigaction(SIGUSR2, &sigac, 0)) == -1)
		errors("Error sigaction\n");
	while (1)
		pause();
	return (0);
}