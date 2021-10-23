#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../printf/ft_printf.h"
#include "../libft/libft.h"

/* void my_handler(int signum, siginfo_t *pid, void *context)
{
	int	i;

	i = 0;
	context = NULL;
	i = ft_printf("Not needed param %s\n", context);
	i = ft_printf("Signum is %d\n", signum);
	i = ft_printf("It's PID is %u\n", pid->si_pid);
	ft_putnbr_fd(i, 1);
} */

int main(void)
{
	struct sigaction sigac;
	/* sigset_t	set;
	siginfo_t	pid; */

	memset(&sigac, 0, sizeof(sigac));
	ft_printf("PID is %i\n", getpid());
	sigac.sa_flags = SA_SIGINFO;
	sigac.sa_sigaction = my_handler;
	sigaction(SIGTERM, &sigac, NULL);

	sleep(100);
	ft_printf("Done from main\n");
	
	return (0);
	/* sigac.sa_handler = my_handler;
	sigemptyset(&set);
	sigaddset(&set, SIGUSR1);
	sigaddset(&set, SIGUSR2);
	sigac.sa_mask = set;
	sigaction(SIGUSR1, &sigac, 0);
	sigaction(SIGUSR2, &sigac, 0);
	raise(SIGUSR1);
	exit (0); */
	//we installed our handler for signals SIGUSR1 and 2, also mentioned these
	//signals should be blocked while handler is working
}

//to send signal to process we could use func: int kill(pid_t pid, int sig);
//func int raise(int sig); sends signal to itself
//func getpid(); returns PID of the current process