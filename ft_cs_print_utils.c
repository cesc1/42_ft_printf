/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cs_print_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguirre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:02:17 by faguirre          #+#    #+#             */
/*   Updated: 2024/10/09 11:02:20 by faguirre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf_utils.h"

// If printing an %i%d%u, manage the 0-. interaction outside
void	print_width(char *str, t_cs cs, int *result)
{
	int		n;
	int		i;
	char	spacing_char;

	if (!str)
		return (NULL);
	spacing_char = ' ';
	if (cs.is_zero)
		spacing_char = '0';
	n = (int)ft_strlen(str);
	if (cs.width > n)
	{
		if (cs.is_neg)
			result = strjoin_free(result, str, 1);
		i = -1;
		while (++i < cs.width - n)
			result = strjoin_free(result, strdup_char(spacing_char), 3);
		if (!cs.is_neg)
			result = strjoin_free(result, str, 1);
	}
	else
		result = strjoin_free(result, str, 1);
	return (result);
}
