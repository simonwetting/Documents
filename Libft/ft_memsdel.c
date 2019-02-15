/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memsdel.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/02 10:56:25 by swetting       #+#    #+#                */
/*   Updated: 2019/02/15 15:56:54 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memsdel(void **ap, size_t n)
{
	ft_bzero(*ap, n);
	ft_memdel(ap);
}
