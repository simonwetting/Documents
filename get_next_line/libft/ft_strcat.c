/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcat.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 13:34:36 by swetting       #+#    #+#                */
/*   Updated: 2019/02/07 17:02:15 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t len_s1;

	len_s1 = ft_strlen(s1);
	while (*s2)
	{
		s1[len_s1] = *s2;
		len_s1++;
		s2++;
	}
	s1[len_s1] = '\0';
	return (s1);
}
