//
#include "libftprintf.h"
#include <stdarg.h>
#include <stdlib.h>

static void	print_cs_u(t_cs cs, va_list args)
{
	unsigned int	num;
	int	n;
	char	*result;
		
	num = va_arg(args, unsigned int);
	result = ft_strdup(ft_itoa(num));
	n = (int)ft_strlen(result);
	while (cs.precision > n++)
		result = strjoin_free("0", result, 2);
	if (cs.is_neg || cs.precision != -1)
		cs.is_zero = 0;
	print_width(result, cs);
	free(result);
}

static void	print_cs_d(t_cs cs, va_list args)
{
	int	num;
	int	n;
	char	*result;
		
	num = va_arg(args, int);
	result = ft_itoa(num);
	if ((cs.is_space || cs.is_pos) && num >= 0)
	{
		if (cs.is_space && !cs.is_pos)
			result = ft_strjoin(" ", result);
		else
			result = ft_strjoin("+", result);
	}
	else
		result = ft_strdup(ft_itoa(num));
	n = (int)ft_strlen(result);
	while (cs.precision > n++)
		result = strjoin_free("0", result, 2);
	if (cs.is_neg || cs.precision != -1)
		cs.is_zero = 0;
	print_width(result, cs);
	free(result);
}

static void	print_cs_s(t_cs cs, va_list args)
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

static void	print_cs_c(t_cs cs, va_list args)
{
	unsigned char	c;
	unsigned char	str[2];

	c = va_arg(args, int);
	cs.is_zero = 0;
	str[0] = c;
	str[1] = '\0';
	print_width((char *)str, cs);
}

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
