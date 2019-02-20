/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/21 15:16:43 by swetting       #+#    #+#                */
/*   Updated: 2019/02/15 15:56:05 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	isnegative(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

char		*ft_itoa(int n)
{
	char			*s;
	unsigned int	len;
	unsigned int	i;
	unsigned char	negative;

	len = ft_intlen(n);
	negative = isnegative(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (negative)
		n *= -1;
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (s == NULL)
		return (NULL);
	s[len] = '\0';
	i = 1;
	while (i <= len - negative)
	{
		s[len - i] = '0' + n % 10;
		n /= 10;
		i++;
	}
	if (negative)
		s[len - i] = '-';
	return (s);
}
