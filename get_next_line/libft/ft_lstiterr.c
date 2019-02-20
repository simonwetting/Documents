/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstiterr.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/23 13:27:30 by swetting       #+#    #+#                */
/*   Updated: 2019/02/06 14:01:24 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiterr(t_list *lst, void (*f)(t_list *elem))
{
	if (lst == NULL)
		return ;
	if (lst->next)
		ft_lstiterr(lst->next, f);
	f(lst);
}
