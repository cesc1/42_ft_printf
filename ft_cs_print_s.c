//
#include "libftprintf_utils.h"
#include "libft/libft.h"
#include <stdarg.h>
#include <stdlib.h>

void	print_cs_s(t_cs cs, va_list args)
{
	char	*s;

	s = va_arg(args, char *);
	cs.is_zero = 0;
	if (cs.precision != -1 && cs.precision < (int)ft_strlen(s))
	{
		s = ft_substr(s, 0, cs.precision);
		if (!s)
			return ;
		print_width(s, cs);
		free(s);
	}
	else
		print_width(s, cs);
}

void	print_cs_c(t_cs cs, va_list args)
{
	unsigned char	c;
	unsigned char	str[2];

	c = va_arg(args, int);
	cs.is_zero = 0;
	str[0] = c;
	str[1] = '\0';
	print_width((char *)str, cs);
}
