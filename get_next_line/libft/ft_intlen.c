/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_intlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/09 14:04:27 by swetting       #+#    #+#                */
/*   Updated: 2019/02/09 14:47:09 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	ft_intlen(int n)
{
	char	len;

	len = 1;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 9 || n < -9)
	{
		n /= 10;
		len++;
	}
	return (len);
}
