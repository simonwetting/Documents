/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/18 13:47:29 by swetting       #+#    #+#                */
/*   Updated: 2019/02/08 14:43:53 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	void *mem;

	mem = (void *)malloc(sizeof(char) * size);
	if (mem == NULL)
		return (NULL);
	while (size > 0)
	{
		((char *)mem)[size - 1] = 0;
		size--;
	}
	return ((char *)mem);
}
