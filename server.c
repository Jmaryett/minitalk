#include "server.h"

static void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_handler(int signum, siginfo_t *sig, void *context)
{
	static char	symb = NULL;
	static int	power = 0;

	ft_putnbr_fd(signum, 1);
	write (1, "\n", 1);
	if (signum == SIGUSR1)
		symb += (128 >> power);
	power += 1;
	if (power == 8)
	{
		ft_putchar(symb);
		power = 0;
		symb = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sigac;
	int					pid;

	ft_putstr_fd("Server started!\n", 1);
	ft_putstr_fd("PID: ", 1);
	pid = getpid();
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	sigac.sa_flags = SA_SIGINFO;
	sigac.sa_sigaction = ft_handler;
	if (sigaction(SIGUSR1, &sigac, 0) == -1)
		errors("Error in sigaction");
	if (sigaction(SIGUSR2, &sigac, 0) == -1)
		errors("Error in sigaction!");
	while (1)
		pause();
	return (0);
}