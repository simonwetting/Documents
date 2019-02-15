/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsplit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/19 15:18:08 by swetting       #+#    #+#                */
/*   Updated: 2019/02/15 17:29:54 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**create_empty_fields(const char *s, char delimiter)
{
	unsigned int	field_count;
	char			**fields;

	field_count = ft_strcofi(s, delimiter);
	fields = (char **)malloc(sizeof(char *) * field_count + 1);
	if (fields == NULL)
		return (NULL);
	fields[field_count] = NULL;
	return (fields);
}

static char	**do_ft_strsplit(char const *s, char c)
{
	unsigned int	field_count;
	unsigned int	i;
	unsigned int	begin_field;
	char			**fields;

	fields = create_empty_fields(s, c);
	if (fields == NULL)
		return (NULL);
	i = 0;
	field_count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			begin_field = i;
			while (s[i] != c && s[i])
				i++;
			fields[field_count] = ft_strsub(s, begin_field, i - begin_field);
			field_count++;
		}
		else
			i++;
	}
	return (fields);
}

char		**ft_strsplit(char const *s, char c)
{
	if (s == NULL)
		return (NULL);
	return (do_ft_strsplit(s, c));
}
