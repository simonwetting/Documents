/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memalloc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/18 10:55:36 by swetting       #+#    #+#                */
/*   Updated: 2019/02/06 15:17:31 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void *mem;

	if (size == 0)
		return (NULL);
	mem = (void *)malloc(size);
	if (mem == NULL)
		return (mem);
	while (size > 0)
		((char *)mem)[size-- - 1] = 0;
	return (mem);
}
