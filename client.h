# ifndef CLIENT_H

#	define CLIENT_H

# include "libft/libft.h"
//# include "printf/ft_printf.h"
# include <signal.h>

//void	ft_handler(int signum, siginfo_t *sig, void *context);
void	send_str(int pid, char *s);
void	converting_to_bits(char c, int pid);
void	errors(char *s);

#endif