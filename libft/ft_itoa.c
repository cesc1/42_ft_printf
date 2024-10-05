/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguirre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 21:02:56 by faguirre          #+#    #+#             */
/*   Updated: 2024/09/23 15:45:00 by faguirre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	count_chars(long num, int result)
{
	if (num > 0)
	{
		return (count_chars(num / 10, result + 1));
	}
	if (num < 0)
	{
		return (count_chars(-num, result + 1));
	}
	if (result == 0)
		return (1);
	return (result);
}

static int	manage_negatives(long *num, char *result)
{
	if (*num < 0)
	{
		*num = -(*num);
		result[0] = '-';
		return (1);
	}
	return (0);
}

char	*ft_itoa(int n)
{
	long	num;
	char	*result;
	int		size;
	int		is_neg;

	num = n;
	size = count_chars(num, 0);
	result = (char *)malloc((size + 1) * sizeof (char));
	if (!result)
	{
		return (result);
	}
	is_neg = manage_negatives(&num, result);
	result[size] = '\0';
	while (--size >= is_neg)
	{
		result[size] = (num % 10) + '0';
		num = num / 10;
	}
	return (result);
}
