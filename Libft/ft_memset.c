/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   memset.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/13 13:54:07 by swetting      #+#    #+#                 */
/*   Updated: 2019/01/13 17:18:57 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	while (len > 0)
		((unsigned char *)b)[--len] = c;
	return (b);
}
