/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/13 17:42:11 by swetting       #+#    #+#                */
/*   Updated: 2019/02/15 15:54:12 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	while (n-- > 0)
		((unsigned char*)dst)[n] = ((unsigned char *)src)[n];
	return (dst);
}
