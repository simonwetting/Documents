/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/15 18:03:30 by swetting       #+#    #+#                */
/*   Updated: 2019/02/27 16:30:37 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char	*read_to_buf(fb_t *fb)
{
	char	*data_read;
	int		bytes_read;
	// void	*free_this;

	data_read = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	ft_bzero(data_read, BUFF_SIZE);
	while (!ft_strchr(fb->buf + fb->index, '\n'))
	{
		bytes_read = read(fb->fd, data_read, BUFF_SIZE);
		if (!bytes_read)
			break;
		if (bytes_read < BUFF_SIZE)
			data_read[bytes_read] = '\0';
		// free_this = fb->buf;
		fb->buf = ft_strjoin(fb->buf + fb->index, data_read);
		// free(free_this);
		fb->index = 0;
	}
	free(data_read);
	return (fb->buf);
}

char	*read_line_from_buf(fb_t *fb)
{
	char 	*line_feed;
	char	*line;

	line_feed = ft_strchr(fb->buf + fb->index, '\n');
	if (!line_feed)
		fb->buf = read_to_buf(fb);
	line_feed = ft_strchr(fb->buf + fb->index, '\n');
	if (!line_feed)
	{
		if (!*(fb->buf + fb->index))
			return (NULL);
		line = fb->buf + fb->index;
		fb->buf = ft_strdup("");
		return (line);
	}
	line = ft_strsub(fb->buf + fb->index, 0, line_feed - fb->buf - fb->index);
	fb->index = line_feed - fb->buf + 1;
	return (line);
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
	fb->index = 0;
	fb->buf = ft_strdup("");
	fb->buf = read_to_buf(fb);
	fb->next = NULL;
	return (fb);
}

int		get_next_line(const int fd, char **line)
{
	static fb_t	*fb;
	fb_t		*cur_fb;

	if (fd == -1)
		return (-1);
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
	*line = read_line_from_buf(cur_fb);
	return (*line ? 1 : 0);
}
