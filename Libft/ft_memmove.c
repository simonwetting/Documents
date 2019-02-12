/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 11:03:29 by swetting      #+#    #+#                 */
/*   Updated: 2019/01/14 11:33:14 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	n;
	char			*temp;

	temp = (char *)malloc(sizeof(char) * len);
	n = 0;
	while (n < len)
	{
		temp[n] = ((char *)src)[n];
		n++;
	}
	n = 0;
	while (n < len)
	{
		((char *)dst)[n] = temp[n];
		n++;
	}
	return (dst);
}
