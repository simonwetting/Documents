/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 11:37:40 by swetting      #+#    #+#                 */
/*   Updated: 2019/01/14 12:25:03 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	void	*p;

	p = (unsigned char *)s + n;
	while (s != p)
	{
		if (*((unsigned char *)s) == (unsigned char)c)
			return ((unsigned char *)s);
		s++;
	}
	return (0);
}
