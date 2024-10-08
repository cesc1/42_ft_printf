//
#include "libftprintf_utils.h"
#include "libft/libft.h"
#include <stdarg.h>
#include <stdlib.h>

char	*print_cs_u(t_cs cs, va_list args)
{
	unsigned int	num;
	int	n;
	char	*str;
	char	*result;
		
	num = va_arg(args, unsigned int);
	str = ft_itoa(num);
	if (!str)
		return (NULL);
	n = (int)ft_strlen(str);
	while (cs.precision > n++)
		str = strjoin_free("0", str, 2);
	if (!str)
		return (NULL);
	if (cs.is_neg || cs.precision != -1)
		cs.is_zero = 0;
	result = print_width(str, cs);
	free(str);
	return (result);
}

char	*print_cs_d(t_cs cs, va_list args)
{
	int	num;
	int	n;
	char	*str;
	char	*result;
		
	num = va_arg(args, int);
	str = ft_itoa(num);
	if (!str)
		return (NULL);
	n = (int)ft_strlen(str);
	while (cs.precision > n++)
		str = strjoin_free("0", str, 2);
	if ((cs.is_space || cs.is_pos) && num >= 0)
	{
		if (cs.is_space && !cs.is_pos)
			str = strjoin_free(" ", str, 2);
		else
			str = strjoin_free("+", str, 2);
	}
	if (cs.is_neg || cs.precision != -1)
		cs.is_zero = 0;
	result = print_width(str, cs);
	free(str);
	return (result);
}
