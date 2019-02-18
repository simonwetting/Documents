/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 14:24:24 by swetting       #+#    #+#                */
/*   Updated: 2019/02/15 15:57:55 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		len_needle;

	len_needle = ft_strlen(needle);
	if (!*needle)
		return ((char *)haystack);
	while (*haystack && len-- >= len_needle)
	{
		if (*haystack++ == *needle)
			if (ft_strncmp(haystack - 1, needle, len_needle) == 0)
				return ((char *)(haystack - 1));
	}
	return (NULL);
}
