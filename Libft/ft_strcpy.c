/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 13:51:24 by swetting      #+#    #+#                 */
/*   Updated: 2019/01/16 13:45:47 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dst, const char *src)
{
	int n;

	n = 0;
	while (src[n])
	{
		dst[n] = src[n];
		n++;
	}
	return (dst);
}
