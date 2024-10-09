/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf_utils.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguirre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:03:43 by faguirre          #+#    #+#             */
/*   Updated: 2024/10/09 11:37:47 by faguirre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_UTILS_BONUS_H
# define LIBFTPRINTF_UTILS_BONUS_H

# include <stdarg.h>

typedef struct s_cs
{
	char	cs;
	char	is_hash;
	char	is_zero;
	char	is_neg;
	char	is_space;
	char	is_pos;
	int		width;
	int		precision;
	char	load_ok;
}	t_cs;

// General utils
char	*char_in(const char *str, const char *set);
char	*strjoin_free(char *str1, char *str2, unsigned int num_free);
char	*strdup_char(char c);

// Manage %conversion_specifiers.
t_cs	load_cs(const char **str);
char	*print_cs(t_cs cs, va_list args);
char	*print_cs_d(t_cs cs, va_list args);
char	*print_cs_u(t_cs cs, va_list args);
char	*print_cs_s(t_cs cs, va_list args);
char	*print_cs_c(t_cs cs, va_list args);
char	*print_cs_x(t_cs cs, va_list args);
char	*print_cs_x1(t_cs cs, va_list args);
char	*print_cs_p(t_cs cs, va_list args);
char	*print_width(char *str, t_cs cs);

#endif
