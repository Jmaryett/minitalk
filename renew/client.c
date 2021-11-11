#include "minitalk.h"

void	send_bits(int pid, char c)
{
	int	i;

	i = 128;
	while(i > 0)
	{
		if ((i & c) != 0)
		{
			kill(pid, SIGUSR1);
			ft_putnbr(1);
		}
		else
		{
			kill(pid, SIGUSR2);
			ft_putnbr(0);
		}
		i /= 2;
	}
	usleep(600);
}

void	send_str(int pid, char *s)
{
	int	i;

	i = 0;
	ft_putnbr(pid);
	write(1, "\n", 1);
	while(s[i] != '\0')
	{
		send_bits(pid, s[i]);
		ft_putchar('\n');
		i++;
	}
	return ;
}

void	ft_handler(int signum, siginfo_t *siginfo, void *unused)
{
	unused = NULL;
	(void)siginfo;
	ft_putnbr(signum);
	write(1, "  - Signal returned from service\n", 35);
}

int	main(int argc, char **argv)
{
	struct sigaction	sig;

	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = ft_handler;
	sigaction(SIGUSR2, &sig, 0);
	if (argc == 3)
		send_str(ft_atoi(argv[1]), argv[2]);
	else
		errors("Wrong args!\n");
	while (1)
		pause();
	return (0);
}