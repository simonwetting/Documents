/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 13:15:41 by swetting       #+#    #+#                */
/*   Updated: 2019/02/07 18:04:14 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*temp;

	len = ft_strlen(s1);
	temp = (char *)malloc(sizeof(char) * len);
	while (len > 0)
	{
		len--;
		temp[len] = s1[len];
	}
	return (temp);
}
