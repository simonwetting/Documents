/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdel.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/21 17:39:38 by swetting       #+#    #+#                */
/*   Updated: 2019/02/06 14:53:38 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (alst == NULL)
		return ;
	if ((*alst)->next != NULL)
	{
		ft_lstdel(&((*alst)->next), del);
		(*alst)->next = NULL;
	}
	ft_lstdelone(alst, del);
}
