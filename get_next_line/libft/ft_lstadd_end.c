/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_end.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/24 14:47:12 by swetting       #+#    #+#                */
/*   Updated: 2019/02/15 15:56:12 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_end(t_list *link, t_list *new)
{
	if (link == NULL || new == NULL)
		return ;
	while (link->next != NULL)
		link = link->next;
	link->next = new;
}
