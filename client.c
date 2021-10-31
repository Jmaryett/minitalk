#include "client.h"
#include "server.h"

static void	converting_to_bits(char c, int pid)
{
	int	i;

	i = 0;
	while(i)
	{
		if (c & i == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i /= 2;
	}
	usleep(100);
}

static void	send_str(int pid, char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		converting_to_bits(s[i], pid);
		i++;
	}
	//converting_to_bits(0, pid);
}

/* void	ft_handler(int signum, siginfo_t *siginfo, void *context)
{
	(void)context;
	(void)siginfo;
	(void)signum;
	ft_printf("Signal recieved\n");
} */

int	main(int argc, char **argv)
{
	//struct sigaction	sigac;

/* 	sigac.sa_flags = SA_SIGINFO;
	sigac.sa_sigaction = ft_handler;
	if (sigaction(SIGUSR1, &sigac, NULL) == -1 ||
		sigaction(SIGUSR2, &sigac, NULL) == -1)
		errors("Error in sigaction"); */
	if (argc != 3)
		errors("Wrong arguments");
	send_str(atoi(argv[1]), argv[2]);
}
