/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tolower.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/18 10:47:21 by swetting       #+#    #+#                */
/*   Updated: 2019/01/24 13:06:15 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}