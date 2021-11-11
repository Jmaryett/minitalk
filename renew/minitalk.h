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

void	errors(char *s);
int		ft_atoi(const char *str);
void	errors(char *s);
void	ft_putchar(char c);
void	ft_putnbr(int n);

void	my_handler(int signum, siginfo_t *siginfo, void *unused);
void	errors(char *s);
void	send_str(int pid, char *s);
void	send_bits(int pid, char c);

#endif