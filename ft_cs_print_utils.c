//
#include "libft/libft.h"
#include "libftprintf_utils.h"

// If printing an %i%d%u, manage the 0-. interaction outside
char	*print_width(char *str, t_cs cs)
{
	int	n;
	int	i;
	char	spacing_char;
	char	*result;

	if (!str)
		return (NULL);
	spacing_char = ' ';
	if (cs.is_zero)
		spacing_char = '0';
	n = (int)ft_strlen(str);
	result = ft_strdup("");
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