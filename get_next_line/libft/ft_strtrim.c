/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/19 13:44:45 by swetting       #+#    #+#                */
/*   Updated: 2019/02/15 16:31:56 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	istnsp(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	char			*ns;
	unsigned int	len_ns;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	while (istnsp(*s))
		s++;
	len_ns = ft_strlen(s);
	if (len_ns == 0)
		return (ft_strdup(""));
	while (istnsp(s[len_ns - 1]))
		len_ns--;
	ns = (char *)malloc(sizeof(char) * (len_ns + 1));
	if (ns == NULL)
		return (NULL);
	i = 0;
	while (i < len_ns)
	{
		ns[i] = s[i];
		i++;
	}
	ns[len_ns] = '\0';
	return (ns);
}
