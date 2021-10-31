#include "client.h"
#include "server.h"

void	errors(char *s)
{
	ft_putstr_fd(s, 1);
	exit (1);
}
