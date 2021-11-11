#ifndef MINITALK_H

# define MINITALK_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stddef.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <signal.h>

void	sv_handler(int signum, siginfo_t *siginfo, void *unused);
//void	ft_handler(int signum, siginfo_t *sig, void *context);
void	errors(char *s);
void	cl_handler(int signum, siginfo_t *sig, void *context);
int		send_str(int pid, char *s);
void	converting_to_bits(char c, int pid);
//void	converting_to_bits(char ascii, int power, int pid);

void	errors(char *s);
int	ft_atoi(const char *str);
void	errors(char *s);
void	ft_putchar(char c);
void	ft_putnbr(int n);

#endif