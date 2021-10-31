#ifndef SERVER_H

# define SERVER_H

# include "libft/libft.h"
# include "printf/ft_printf.h"
# include <signal.h>

void	ft_handler(int signum, siginfo_t *sig, void *context);
void	errors(char *s);

#endif