/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguirre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:02:44 by faguirre          #+#    #+#             */
/*   Updated: 2024/10/09 11:02:47 by faguirre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_utils_bonus.h"
#include "libft/libft.h"
#include <stdarg.h>
#include <stdlib.h>

static char	*recalculate_str(const char *str, va_list args)
{
	t_cs	cs;
	char	*result;

	result = ft_strdup("");
	while (*str)
	{
		if (*str == '%')
		{
			cs = load_cs(&str);
			if (cs.load_ok)
				result = strjoin_free(result, print_cs(cs, args), 3);
			else
				result = strjoin_free(result, strdup_char(*str), 3);
		}
		else
			result = strjoin_free(result, strdup_char(*str), 3);
		if (!result)
			return (result);
		str++;
	}
	return (result);
}

int	ft_printf(char const *str, ...)
{
	int		n;
	va_list	args;
	char	*result;

	if (!str)
		return (-1);
	va_start(args, str);
	result = recalculate_str(str, args);
	va_end(args);
	if (!result)
		return (-1);
	n = ft_strlen(result);
	ft_putstr_fd(result, 1);
	free(result);
	return (n);
}
