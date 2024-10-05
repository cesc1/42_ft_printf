//
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"

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

int	ft_printf(char const *str, ...);
char	*char_in(const char *str, const char *set);
t_cs	load_cs(const char **str);

#endif
