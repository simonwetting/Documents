/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_cupcase.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/24 13:02:21 by swetting       #+#    #+#                */
/*   Updated: 2019/01/24 13:08:17 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	ft_cupcase(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
