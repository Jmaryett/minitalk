/* #include "server.h"

void	ft_handler(int signum, siginfo_t *sig, void *context)
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
		write(1, "1", 1);
	}
	else if (signum == SIGUSR2)
		write(1, "0", 1);
	power += 1;
	if (power == 8)
	{
		write(1, &symb, 1);
		write (1, "\n", 1);
		power = 0;
		symb = 0;
 		if (kill(sig->si_pid, SIGUSR1) == -1)
			errors("Error in returned signal!\n");
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sigac;
	int					pid;

	(void)argv;
	if (argc != 1)
		errors("Wrong arguments!\n");
	write(1, "Server started!\nPID: ", 21);
	pid = getpid();
	ft_putnbr_fd(pid, 1);
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

#include "server.h"

void	sig_to_str(int bin)
{
	char	c;
	int		i;

	i = 0;
	c = '\0';
	c += (bin << i++);
	if (i > 7)
	{
		if (c == '\0')
			ft_putchar_fd('\n', 1);
		else
			ft_putchar_fd(c, 1);
		c = 0;
		i = 0;
	}
}

void	my_handler(int signum, siginfo_t *siginfo, void *unused)
{
	static int	ascii = 0;
	static int	power = 0;
	unsigned char c;

	(void)unused;
	c = 0;
	if (signum == SIGUSR1)
		ascii += 1 << (7 - power);
	power += 1;
	if (power == 8)
	{
		c = (unsigned char)ascii;
		write(1, &c, 1);
		power = 0;
		ascii = 0;
		if (kill(siginfo->si_pid, SIGUSR2) == -1)
			errors("Error signal\n");
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	catch;

	(void)argv;
	if (argc != 1)
		errors("Error arguments\n");
	write(1, "Server started!\nPID: ", 21);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	catch.sa_flags = SA_SIGINFO;
	catch.sa_sigaction = my_handler;
	if ((sigaction(SIGUSR1, &catch, 0)) == -1)
		errors("Error sigaction\n");
	if ((sigaction(SIGUSR2, &catch, 0)) == -1)
		errors("Error sigaction\n");
	while (1)
		pause();
	return (0);
}