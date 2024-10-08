//
#include "libft/libft.h"
#include "libftprintf_utils.h"

// If printing an %i%d%u, manage the 0-. interaction outside
void	print_width(char *str, t_cs cs)
{
	int	n;
	char	spacing_char;
	int	i;

	spacing_char = ' ';
	if (cs.is_zero)
		spacing_char = '0';
	n = (int)ft_strlen(str);
	i = -1;
	if (cs.width > n)
	{
		if (cs.is_neg)
			ft_putstr_fd(str, 1);
		while (++i < cs.width - n)
			ft_putchar_fd(spacing_char, 1);
		if (!cs.is_neg)
			ft_putstr_fd(str, 1);
	}
	else
		ft_putstr_fd(str, 1);
}