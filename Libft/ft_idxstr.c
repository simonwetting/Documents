/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_idxstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/21 12:02:44 by swetting       #+#    #+#                */
/*   Updated: 2019/02/09 13:20:37 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

static	int		**new_index(int field_count)
{
	int		**idx_s;

	idx_s = (int **)malloc(sizeof(int *) * (field_count + 1));
	idx_s[0] = (int *)malloc(sizeof(int));
	idx_s[0][0] = field_count;
	return (idx_s);
}

int				**ft_idxstr(char const *s, char delimiter)
{
	int		**idx_s;
	int		field_count;
	int		i;

	field_count = ft_strcofi(s, delimiter);
	if (!field_count)
		return (NULL);
	idx_s = new_index(field_count);
	field_count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != delimiter)
		{
			field_count++;
			idx_s[field_count] = (int *)malloc(sizeof(int) * 2);
			idx_s[field_count][0] = i;
			while (s[i] != delimiter && s[i])
				i++;
			idx_s[field_count][1] = i - 1;
		}
		if (s[i])
			i++;
	}
	return (idx_s);
}
