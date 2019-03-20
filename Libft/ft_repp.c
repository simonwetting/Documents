/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_repp.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: simonwetting <simonwetting@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 12:12:37 by simonwettin    #+#    #+#                */
/*   Updated: 2019/03/20 12:13:49 by simonwettin   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_repp(void **old, void *new)
{
	void	*free_this;

	free_this = *old;
	*old = new;
	free(free_this);
}