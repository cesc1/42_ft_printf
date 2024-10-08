//
//
#include "libftprintf_utils.h"
#include "libft/libft.h"
#include <stdarg.h>
#include <stdlib.h>

void	print_cs_u(t_cs cs, va_list args)
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

void	print_cs_d(t_cs cs, va_list args)
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
