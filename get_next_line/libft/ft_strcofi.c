/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcofi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/21 12:15:06 by swetting       #+#    #+#                */
/*   Updated: 2019/02/15 15:54:13 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcofi(char const *s, char delimiter)
{
	int		field_count;

	if (s == NULL)
		return (0);
	field_count = 0;
	while (*s)
	{
		if (*s != delimiter)
		{
			field_count++;
			while (*s != delimiter && *s)
				s++;
		}
		if (*s)
			s++;
	}
	return (field_count);
}
