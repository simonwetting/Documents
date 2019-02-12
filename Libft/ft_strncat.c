/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 13:58:30 by swetting       #+#    #+#                */
/*   Updated: 2019/02/07 17:38:23 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t len_s1;

	if (n < 1)
		return (s1);
	len_s1 = ft_strlen(s1);
	while (*s2 && n > 0)
	{
		n--;
		s1[len_s1] = *s2;
		len_s1++;
		s2++;
	}
	s1[len_s1] = '\0';
	return (s1);
}
