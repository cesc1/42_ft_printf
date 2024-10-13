/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cs_print_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguirre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:02:05 by faguirre          #+#    #+#             */
/*   Updated: 2024/10/09 11:02:07 by faguirre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_utils.h"
#include "libft/libft.h"
#include <stdarg.h>
#include <stdlib.h>

char	*print_cs_s(t_cs cs, va_list args)
{
	char	*s;
	char	*result;

	s = va_arg(args, char *);
	if (!s)
		return (ft_strdup("(null)"));
	cs.is_zero = 0;
	if (cs.precision != -1 && cs.precision < (int)ft_strlen(s))
	{
		s = ft_substr(s, 0, cs.precision);
		if (!s)
			return (NULL);
		result = print_width(s, cs);
		free(s);
	}
	else
		result = print_width(s, cs);
	return (result);
}

void	print_cs_c(t_cs cs, va_list args, int *result)
{
	unsigned char	c;
	unsigned char	str[2];

	c = va_arg(args, int);
	cs.is_zero = 0;
	str[0] = c;
	str[1] = '\0';
	print_width((char *)str, cs, &result);
}
