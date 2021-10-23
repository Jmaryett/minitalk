#include "ft_printf.h"

int main()
{
	int len;
	int p;
	len = ft_printf("%9.2p", 1234);
	printf("\nMy length = %d\n", len);
	p = printf("%9.2p", 1234);
	printf("\nLen that should be = %d", p);

	return (0);
}