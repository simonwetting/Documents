/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/23 13:05:30 by swetting       #+#    #+#                */
/*   Updated: 2019/02/06 15:06:08 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*result;

	if (lst == NULL)
		return (NULL);
	result = f(lst);
	while (lst->next != NULL)
	{
		lst = lst->next;
		ft_lstadd_end(result, f(lst));
	}
	return (result);
}
