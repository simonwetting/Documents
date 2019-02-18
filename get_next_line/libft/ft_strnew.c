/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/18 13:47:29 by swetting       #+#    #+#                */
/*   Updated: 2019/02/15 15:57:51 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	void			*mem;
	unsigned int	i;

	mem = (void *)malloc(sizeof(char) * size + 1);
	if (mem == NULL)
		return (NULL);
	i = 0;
	while (i <= size)
	{
		((char *)mem)[i] = 0;
		i++;
	}
	return ((char *)mem);
}
