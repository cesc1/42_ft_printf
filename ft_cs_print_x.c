/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cs_print_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguirre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:02:29 by faguirre          #+#    #+#             */
/*   Updated: 2024/10/09 12:26:09 by faguirre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_utils.h"
#include "libft/libft.h"
#include <stdarg.h>
#include <stdlib.h>

static char	*itohex(unsigned long num, char is_upper)
{
	const char	hex_l[16] = "0123456789abcdef";
	const char	hex_u[16] = "0123456789ABCDEF";
	char		*hex;
	char		*result;

	if (is_upper)
		hex = (char *)hex_u;
	else
		hex = (char *)hex_l;
	result = ft_strdup("");
	if (num == 0)
	{
		free(result);
		return (ft_strdup("0"));
	}
	while (num > 0)
	{
		result = strjoin_free(strdup_char(hex[num % 16]), result, 3);
		num /= 16;
	}
	return (result);
}

char	*print_cs_x(t_cs cs, va_list args)
{
	unsigned int	num;
	int				n;
	char			*result;
	char			*str;

	num = va_arg(args, unsigned int);
	str = itohex(num, 0);
	if (!str)
		return (NULL);
	n = (int)ft_strlen(str);
	if (cs.is_neg || cs.precision != -1)
		cs.is_zero = 0;
	if (cs.is_hash && cs.is_zero && num != 0)
	{
		cs.precision = cs.width - 2;
		cs.width = 0;
	}
	while (cs.precision > n++)
		str = strjoin_free("0", str, 2);
	if (cs.is_hash && num != 0)
		str = strjoin_free("0x", str, 2);
	result = print_width(str, cs);
	free(str);
	return (result);
}

char	*print_cs_x1(t_cs cs, va_list args)
{
	unsigned int	num;
	int				n;
	char			*result;
	char			*str;

	num = va_arg(args, unsigned int);
	str = itohex(num, 1);
	if (!str)
		return (NULL);
	n = (int)ft_strlen(str);
	if (cs.is_neg || cs.precision != -1)
		cs.is_zero = 0;
	if (cs.is_hash && cs.is_zero && num != 0)
	{
		cs.precision = cs.width - 2;
		cs.width = 0;
	}
	while (cs.precision > n++)
		str = strjoin_free("0", str, 2);
	if (cs.is_hash && num != 0)
		str = strjoin_free("0X", str, 2);
	result = print_width(str, cs);
	free(str);
	return (result);
}

char	*print_cs_p(t_cs cs, va_list args)
{
	int		n;
	void	*ptr;
	char	*str;
	char	*result;

	ptr = va_arg(args, void *);
	if (!ptr)
		return (ft_strdup("(null)"));
	str = itohex((unsigned long)ptr, 0);
	if (!str)
		return (NULL);
	n = (int)ft_strlen(str);
	if (cs.is_neg || cs.precision != -1)
		cs.is_zero = 0;
	if (cs.is_zero)
	{
		cs.precision = cs.width - 2;
		cs.width = 0;
	}
	while (cs.precision > n++)
		str = strjoin_free("0", str, 2);
	str = strjoin_free("0x", str, 2);
	result = print_width(str, cs);
	free(str);
	return (result);
}
