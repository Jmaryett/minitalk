#include "./libft/libft.h"
#include "server.h"
#include "client.h"

void	errors(char *s)
{
	ft_putstr_fd(s, 1);
	exit (1);
}
