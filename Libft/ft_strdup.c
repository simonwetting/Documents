/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 13:15:41 by swetting       #+#    #+#                */
/*   Updated: 2019/02/15 15:57:12 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*temp;

	len = ft_strlen(s1);
	temp = (char *)malloc(sizeof(char) * (len + 1));
	if (temp == NULL)
		return (NULL);
	temp[len] = '\0';
	while (len > 0)
	{
		len--;
		temp[len] = s1[len];
	}
	return (temp);
}
