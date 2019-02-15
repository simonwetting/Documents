/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/19 10:59:48 by swetting       #+#    #+#                */
/*   Updated: 2019/02/15 15:57:40 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*s_new;
	size_t	len_s;
	int		i;

	if (s == NULL || f == NULL)
		return (NULL);
	len_s = ft_strlen(s);
	s_new = (char *)malloc(sizeof(char) * (len_s + 1));
	if (s_new == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		s_new[i] = f(i, s[i]);
		i++;
	}
	s_new[i] = '\0';
	return (s_new);
}
