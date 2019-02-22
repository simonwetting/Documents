/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   resizable_string.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/22 15:28:48 by swetting       #+#    #+#                */
/*   Updated: 2019/02/22 16:32:44 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "resizable_string.h"

rstr_t	*new_rstr(const char *str)
{
	rstr_t		*new_rstr;

	new_rstr = (rstr_t *)malloc(sizeof(rstr_t));
	new_rstr->str = ft_strdup(str);
	new_rstr->size = ft_strlen(str);
	return (new_rstr);
}

rstr_t	*new_rstrn(const char *str, size_t len)
{
	rstr_t		*new_rstr;

	if (ft_strlen(str) < len)
		return (NULL);
	new_rstr = (rstr_t *)malloc(sizeof(rstr_t));
	new_rstr->str = ft_strdup(str);
	new_rstr->size = len;
	return (new_rstr);
}

void	rep_rstr(rstr_t **old, rstr_t *new)
{
	rstr_t	*free_this;

	free_this = *old;
	*old = new;
	free(free_this->str);
	free(free_this);
}

rstr_t	*append_rstr(rstr_t **rstr, const char *str)
{
	size_t	len_str;
	size_t	len_appendage;
	rstr_t	*new_rstr;

	len_str = ft_strlen((*rstr)->str);
	len_appendage = ft_strlen(str);
	if (len_str + len_appendage + 1 < (*rstr)->size)
	{
		new_rstr = new_rstrn(str, len_str + len_appendage);
		ft_strcpy(new_rstr->str, (*rstr)->str);
		//new_rstr->size = len_str + len_appendage;
		rep_rstr(rstr, new_rstr);
	}
	ft_strcpy((*rstr)->str + len_str, str);
	return (*rstr);
}