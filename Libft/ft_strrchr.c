/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 16:33:54 by swetting       #+#    #+#                */
/*   Updated: 2019/01/31 11:01:30 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			len;
	int				pos;
	unsigned int	i;

	len = ft_strlen(s);
	pos = -1;
	i = 0;
	while (i <= len)
	{
		if (s[len - i++] == c)
			pos = len - i + 1;
	}
	return (pos < 0 ? NULL : (char *)s + pos);
}
