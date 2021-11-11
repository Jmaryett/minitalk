#include "minitalk.h"
#include "stdio.h"

void	converting_to_bits(char c, int pid)
{
	int	i;

	i = 128;
	while(i >= 1)
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
		usleep(100);
	}
}

/* void	converting_to_bits(char ascii, int power, int pid)
{
	if (power > 0)
		converting_to_bits(ascii / 2, power - 1, pid);
	if ((ascii % 2) == 1)
	{
		if (kill(pid, SIGUSR1) == -1)
		{
			errors("Error signal!");
			exit(0);
		}
	}
	else
	{
		if (kill(pid, SIGUSR2) == -1)
		{
			errors("Error signal!");
			exit(0);
		}
	}
	usleep(100);
} */

int	send_str(int pid, char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		converting_to_bits(s[i], pid);
		i++;
	}
	return (0);
}

/* void	cl_handler(int signum, siginfo_t *siginfo, void *context)
{
	(void)context;
	(void)siginfo;
	(void)signum;
	write(1, "Recieved signal from server\n", 28);
	return ;
} */

int	main(int argc, char **argv)
{
/* 	struct sigaction	sigac;

  	sigac.sa_flags = SA_SIGINFO;
	sigac.sa_sigaction = cl_handler;
	if (sigaction(SIGUSR2, &sigac, NULL) == -1)
		errors("Error in client sigaction\n"); */
	if (argc == 3)
		send_str(atoi(argv[1]), argv[2]);
	else
		errors("Wrong arguments!\n");
/* 	while (1)
		pause (); */
	return (0);
}
