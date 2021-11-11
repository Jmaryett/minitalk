#include "minitalk.h"

void	my_handler(int signum, siginfo_t *siginfo, void *unused)
{
	static unsigned char	symb;
	static int				power;

	symb = 0;
	power = 0;
	unused = NULL;
	(void)siginfo;
	if (signum == SIGUSR1)
		symb += ((unsigned char)128 >> power);
	power += 1;
	if (power == 8)
	{
		write(1, &symb, 1);
		symb = 0;
		power = 0;
		kill(siginfo->si_pid, SIGUSR2);
	}
	
}

int	main(int argc, char **argv)
{
	struct sigaction sigact;

	(void)argv;
	if (argc != 1)
		errors("Wrong args!\n");
	write(1, "Server started!\nPID: ", 21);
	ft_putnbr(getpid());
	ft_putchar('\n');
	sigact.sa_flags = SA_SIGINFO;
	sigact.sa_sigaction = my_handler;
	sigaction(SIGUSR1, &sigact, 0);
	sigaction(SIGUSR2, &sigact, 0);
	while (1)
		pause();
	return (0);
}
