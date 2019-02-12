/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 14:32:52 by swetting       #+#    #+#                */
/*   Updated: 2019/02/08 13:46:57 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

unsigned long	ft_strlcat(char *dst, const char *src, unsigned long size)
{
	unsigned long		len_dst;
	unsigned long		len_src;
	unsigned int		i;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (size < len_dst + 2)
		return (size);
	i = 0;
	while (len_dst + 2 + i <= size && i <= len_src)
	{
		dst[len_dst + i] = *src;
		i++;
		src++;
	}
	dst[len_dst + i] = '\0';
	return (size);
}
