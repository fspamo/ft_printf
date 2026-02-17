#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	int val = 42;
	printf("%d", printf("%k", val));
	printf("\n");
	printf("%d", ft_printf("%k", val));
	printf("\n");
}
