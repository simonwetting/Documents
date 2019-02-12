/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/19 13:44:45 by swetting       #+#    #+#                */
/*   Updated: 2019/02/09 12:33:10 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	char			*ns;
	unsigned int	len_ns;
	unsigned int	i;

	if (s == NULL || *s == '\0')
		return (NULL);
	while (ft_iswhitespace(*s))
		s++;
	len_ns = ft_strlen(s);
	while (ft_iswhitespace(s[len_ns - 1]))
		len_ns--;
	ns = (char *)malloc(sizeof(char) * (len_ns + 1));
	i = 0;
	while (i < len_ns)
	{
		ns[i] = s[i];
		i++;
	}
	return (ns);
}
