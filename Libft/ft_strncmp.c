/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 18:06:49 by swetting       #+#    #+#                */
/*   Updated: 2019/02/08 14:21:40 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s2 && *s1 && n > 1)
	{
		if (*s2 != *s1)
			return (*s1 - *s2);
		s1++;
		s2++;
		n--;
	}
	return (*s1 - *s2);
}
