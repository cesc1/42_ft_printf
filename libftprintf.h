//
#ifndef PRINTF_H
# define PRINTF_H

# include "libft/libft.h"
#include <stdarg.h>

typedef struct s_cs
{
	char	cs;
	char	is_hash;
	char	is_zero;
	char	is_neg;
	char	is_space;
	char	is_pos;
	int	width;
	int	precision;
	char load_ok;
}	t_cs;

// Main function
int	ft_printf(char const *str, ...);

// Utils
char	*char_in(const char *str, const char *set);
char	*strjoin_free(char *str1, char *str2, unsigned int num_free);

// Manage %conversion_specifiers
t_cs	load_cs(const char **str);
void	print_cs(t_cs cs, va_list args);
void	print_width(char *str, t_cs cs);

#endif