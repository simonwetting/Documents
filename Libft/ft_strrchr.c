/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: simonwetting <simonwetting@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 16:33:54 by swetting       #+#    #+#                */
/*   Updated: 2019/03/20 12:07:19 by simonwettin   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			len;
	unsigned int	i;

	len = ft_strlen(s);
	i = 0;
	while (i <= len)
	{
		if (s[len - i] == c)
			return ((char *)s + len - i);
		i++;
	}
	return (0);
}
