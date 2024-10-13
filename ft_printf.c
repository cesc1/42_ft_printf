/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguirre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:02:44 by faguirre          #+#    #+#             */
/*   Updated: 2024/10/12 12:32:40 by faguirre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_utils.h"
#include "libft/libft.h"
#include <stdlib.h>

static void	*calculate_str(const char *str, va_list args, int *result)
{
	t_cs	cs;

	while (*str)
	{
		if (*str == '%')
		{
			cs = load_cs(&str);
			if (cs.load_ok)
				print_cs(cs, args, &result);
			else
				print_char(*str, &result);
		}
		else
			print_char(*str, &result);
		if (result == -1)
			return ;
		str++;
	}
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		result;

	if (!str)
		return (-1);
	result = 0;
	va_start(args, str);
	result = calculate_str(str, args, &result);
	va_end(args);
	return (result);
}
