//
#include "printf.h"

char	*char_in(const char *str, const char *set)
{
	return (ft_strchr(set, *str));
}
