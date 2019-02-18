/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 16:50:52 by swetting       #+#    #+#                */
/*   Updated: 2019/02/15 13:44:08 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(char const *str)
{
	int		result;
	int		negative;

	while (ft_iswhitespace(*str))
		str++;
	negative = 0;
	result = 0;
	if (*str == '+' && *(str + 1) == '-')
		return (0);
	if (*str == '+')
		str++;
	if (*str == '-')
	{
		str++;
		negative = 1;
	}
	while (ft_isdigit(*str))
	{
		result *= 10;
		result += *str++ - '0';
	}
	if (negative)
		result *= -1;
	return (result);
}
