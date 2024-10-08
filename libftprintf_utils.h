//
#ifndef LIBFTPRINTF_UTILS_H
# define LIBFTPRINTF_UTILS_H

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

// General utils
char	*char_in(const char *str, const char *set);
char	*strjoin_free(char *str1, char *str2, unsigned int num_free);

// Manage %conversion_specifiers
t_cs	load_cs(const char **str);
void	print_cs(t_cs cs, va_list args);
void	print_width(char *str, t_cs cs);

#endif
