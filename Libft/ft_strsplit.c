/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsplit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/19 15:18:08 by swetting       #+#    #+#                */
/*   Updated: 2019/02/08 17:16:35 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char	**ft_strsplit(char const *s, char delimiter)
{
	int		**idx_s;
	char	**strings;
	int		i;

	if (s == NULL)
		return (NULL);
	idx_s = ft_idxstr(s, delimiter);
	strings = (char **)malloc(sizeof(char *) * (**idx_s + 1));
	i = 0;
	while (i < **idx_s)
	{
		strings[i] = (char *)malloc(sizeof(char) *
			(idx_s[i + 1][1] - idx_s[i + 1][0] + 1));
		ft_strncpy(strings[i], s + idx_s[i + 1][0],
			idx_s[i + 1][1] - idx_s[i + 1][0] + 1);
		i++;
	}
	strings[i] = NULL;
	return (strings);
}
