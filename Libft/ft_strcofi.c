/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcofi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/21 12:15:06 by swetting       #+#    #+#                */
/*   Updated: 2019/02/09 13:10:07 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strcofi(char const *s, char delimiter)
{
	int		field_count;

	if (s == NULL || *s == '\0' || delimiter == '\0')
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
