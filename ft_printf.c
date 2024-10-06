//
#include "printf.h"
#include <stdarg.h>
#include <stdlib.h>

int	ft_printf(char const *str, ...)
{
	t_cs	cs;
	va_list	args;

	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			cs = load_cs(&str);
			if (cs.load_ok)
				print_cs(cs, args);
			else
				ft_putchar_fd(*str, 1);
		}
		else
			ft_putchar_fd(*str, 1);
		str++;
	}
	va_end(args);
	return (0);
}
