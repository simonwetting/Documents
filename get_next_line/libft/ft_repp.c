/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_repp.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/20 18:32:12 by swetting       #+#    #+#                */
/*   Updated: 2019/02/20 18:34:41 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	repp(void **old, void *new)
{
	void *free_this;

	free_this = *old;
	*old = new;
	free(free_this);
}
