/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstcount.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/23 13:41:10 by swetting       #+#    #+#                */
/*   Updated: 2019/02/11 12:18:12 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_lstcount(t_list *lst)
{
	t_list			*temp;
	unsigned int	n_elem;

	if (lst == NULL)
		return (0);
	temp = lst;
	n_elem = 1;
	while (temp->next)
	{
		temp = temp->next;
		n_elem++;
	}
	return (n_elem);
}
