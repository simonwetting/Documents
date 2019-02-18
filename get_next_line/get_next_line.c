/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: simonwetting <simonwetting@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/15 18:03:30 by swetting       #+#    #+#                */
/*   Updated: 2019/02/17 19:19:04 by simonwettin   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

char	*read_to_buf(int fd)
{
	char	*buf;

	buf = (char *)malloc(sizeof(char) * BUF_SIZE);
	ft_bzero(buf, BUF_SIZE);
	read(fd, buf, BUF_SIZE);
	return (buf);
}

fb_t	*new_fb(const int fd)
{
	fb_t	*file_buffer;

	file_buffer = (fb_t *)malloc(sizeof(fb_t));
	file_buffer->fd = fd;
	file_buffer->buf = read_to_buf(fd);
	return (file_buffer);
}

int		get_next_line(const int fd, char **line)
{
	static fb_t	*file_buffer;

	if (fd < 0)
		return (fd);
	if (file_buffer == 0)
		file_buffer = new_fb(fd);
	return (0);
}
