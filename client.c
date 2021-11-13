#include "minitalk.h"
#include "stdio.h"

//int g_recieve;

void	sending_bits(char c, int pid)
{
	int	i;

	i = 128;
	while(i >= 1)
	{
		//if (g_recieve == 1)
		//{
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
		//	g_recieve = 0;
	//	}
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
	//sending_bits('\0', pid);
	return (0);
}

void	cl_handler(int signum, siginfo_t *siginfo, void *context)
{
	(void)context;
	(void)siginfo;
	(void)signum;
//	g_recieve = 1;
	write(1, "Recieved signal from server\n", 28);
	return ;
}

int	main(int argc, char **argv)
{
 	struct sigaction	sigac;

	//g_recieve = 1;
//	sigemptyset(&sigac.sa_mask);
	//sigaddset(&sigac.sa_mask, SIGINT);
	//sigaddset(&sigac.sa_mask, SIGQUIT);
	//sigaddset(&sigac.sa_mask, SIGUSR1);
  	sigac.sa_flags = SA_SIGINFO;
	sigac.sa_sigaction = cl_handler;
	if (sigaction(SIGUSR2, &sigac, NULL) == -1)
		errors("Error in client sigaction\n");
	if (ft_atoi(argv[1]) < 0)
		errors("Wrong PID!\n");
	if (argc == 3)
		send_str(ft_atoi(argv[1]), argv[2]);
	else
		errors("Wrong arguments!\n");
	sleep(5);
	errors("Something went wrong!\n");
	//while (1)
	//	pause ();
	return (0);
}
