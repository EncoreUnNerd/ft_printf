#include "ft_printf.h"
#include <limits.h>

int	main(void)
{
	ft_printf("ft_printf : %x", LONG_MAX);
	printf("printf : %x", LONG_MAX);
}