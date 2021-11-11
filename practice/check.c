#include <stdio.h>

int main()
{
	unsigned char c = 'A';
	int i = 1;
	char b = c & i;
	int d = b;
	printf("%c, %d\n", b, d);
	//printf("Litter = %c, It's ascii num = %d\n", c, i);
	return (0);
}