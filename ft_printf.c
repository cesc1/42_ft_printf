//
#include "printf.h"
//#include <stdarg.h>


int	ft_printf(char const *str, ...)
{
	t_cs	cs;

	while (*str)
	{
		if (*str == '%')
		{
			cs = load_cs(&str);
			if (cs.load_ok)
			{
				ft_putchar_fd(' ', 1);
			}
			else
				ft_putchar_fd(*str, 1);
		}
		else
			ft_putchar_fd(*str, 1);
		str++;
	}
	return (0);
}
