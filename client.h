# ifndef CLIENT_H

#	define CLIENT_H

# include "libft/libft.h"
# include <signal.h>

void	my_handler(int signum, siginfo_t *sig, void *context);
int		send_str(int pid, char *s);
void	converting_to_bits(char c, int pid);
void	errors(char *s);

#endif