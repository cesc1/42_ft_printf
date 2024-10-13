/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cs_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguirre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:01:45 by faguirre          #+#    #+#             */
/*   Updated: 2024/10/09 12:02:24 by faguirre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_utils.h"
#include "libft/libft.h"
#include <stdarg.h>
#include <stdlib.h>

void	print_cs(t_cs cs, va_list args, int *result)
{
	if (cs.cs == '%')
		print_char('%', &result);
	else if (cs.cs == 'c')
		print_cs_c(cs, args, &result);
	else if (cs.cs == 's')
		result = print_cs_s(cs, args);
	else if (cs.cs == 'i' || cs.cs == 'd')
		result = print_cs_d(cs, args);
	else if (cs.cs == 'u')
		result = print_cs_u(cs, args);
	else if (cs.cs == 'x')
		result = print_cs_x(cs, args);
	else if (cs.cs == 'X')
		result = print_cs_x1(cs, args);
	else if (cs.cs == 'p')
		result = print_cs_p(cs, args);
	else
		*result = -1;
	return (result);
}
