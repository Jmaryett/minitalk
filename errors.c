#include "client.h"
#include "server.h"

void	errors(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	exit (0);
}