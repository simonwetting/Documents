/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strclr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/18 14:47:03 by swetting       #+#    #+#                */
/*   Updated: 2019/02/15 16:23:07 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	size_t len;

	if (s == NULL)
		return ;
	len = ft_strlen(s);
	while (len > 0)
	{
		s[len - 1] = 0;
		len--;
	}
}
