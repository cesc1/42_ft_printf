//
#include "libftprintf_utils.h"
#include "libft/libft.h"
#include <stdarg.h>
#include <stdlib.h>

void    print_cs(t_cs cs, va_list args)
{
	if (cs.cs == '%')
		ft_putchar_fd('%', 1);
	else if (cs.cs == 'c')
		print_cs_c(cs, args);
	else if (cs.cs == 's')
		print_cs_s(cs, args);
	else if (cs.cs == 'i' || cs.cs == 'd')
		print_cs_d(cs, args);
	else if (cs.cs == 'u')
		print_cs_u(cs, args);
}
