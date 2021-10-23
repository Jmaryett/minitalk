#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../printf/ft_printf.h"
#include "../libft/libft.h"

void my_handler(int signum, siginfo_t *pid, void *context)
{
	ft_printf("Signum is %d\n", signum);
	ft_printf("It's PID is %u\n", pid->si_pid);
}

int main()
{
	struct sigaction act;
	unsigned int pid;

	ft_printf("Server starded!\n");
	ft_printf("PID;%u\n", getpid());
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = my_handler;
	sigaction(SIGUSR1, &act, NULL);
	sleep(100);
	sigaction(SIGUSR2, &act, NULL);
	sleep(100);
}