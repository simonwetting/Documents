/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/21 17:09:31 by swetting       #+#    #+#                */
/*   Updated: 2019/02/15 15:56:31 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*link;

	link = (t_list *)malloc(sizeof(t_list));
	if (link == NULL)
		return (NULL);
	link->next = NULL;
	if (content == NULL)
	{
		link->content = NULL;
		link->content_size = 0;
		return (link);
	}
	link->content = (void *)ft_strdup(content);
	link->content_size = content_size;
	return (link);
}
