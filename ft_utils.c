//
#include "libftprintf.h"
#include <stdlib.h>

char	*char_in(const char *str, const char *set)
{
	return (ft_strchr(set, *str));
}

char	*strjoin_free(char *str1, char *str2, unsigned int num_free)
{
	size_t	n1;
	size_t	n2;
	char	*result;

	n1 = ft_strlen(str1);
	n2 = ft_strlen(str2);
	result = (char *)malloc(n1 + n2 + 1);
	ft_strlcpy(result, str1, n1 + 1);
	ft_strlcpy(&result[n1], str2, n2 + 1);
	if (num_free == 1 || num_free >= 3)
		free(str1);
	if (num_free == 2 || num_free >= 3)
		free(str2);
	return (result);
}
