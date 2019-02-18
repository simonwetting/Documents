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
#include <stdio.h>

char	*read_to_buf(int fd)
{
	char	*result;
	char	*buf;


	buf = (char *)malloc(sizeof(char) * BUF_SIZE);
	ft_bzero(buf, BUF_SIZE);
	read(fd, buf, BUF_SIZE);
	printf("buf>>%s\n", buf);
	result = ft_strdup(buf);
	if (ft_strchr(buf, '\n') == NULL)
	{
		ft_bzero(buf, BUF_SIZE);
		read(fd, buf, BUF_SIZE);
		result = ft_strjoin(result, buf);
	}
	return (result);
}

void	add_fb(fb_t **begin_list, fb_t *new_buffer)
{
	new_buffer->next = *begin_list;
	*begin_list = new_buffer;
}

fb_t	*new_fb(const int fd)
{
	fb_t	*fb;

	fb = (fb_t *)malloc(sizeof(fb_t));
	fb->fd = fd;
	fb->buf = read_to_buf(fd);
	fb->index = 0;
	fb->next = NULL;
	return (fb);
}

char	*next_line_to_char(fb_t *buffer)
{
	char	*line;
	char	*buf;
	char	*next_newline;

	buf = buffer->buf + buffer->index;
	next_newline = ft_strchr(buf, '\n');
	line = ft_strsub(buf, 0, next_newline - buf);
	printf("line>%s\n%i\n", next_newline, next_newline - buf);
	return (line);
}

int		get_next_line(const int fd, char **line)
{
	static fb_t	*fb;
	fb_t		*cur_fb;

	if (fd < 0)
		return (fd);
	if (fb == NULL)
		fb = new_fb(fd);
	cur_fb = fb;
	while (cur_fb->fd != fd)
		cur_fb = cur_fb->next;
	if (cur_fb == NULL)
	{
		cur_fb = new_fb(fd);
		add_fb(&fb, cur_fb);
	}
	*line = next_line_to_char(cur_fb);
	return (1);
}
