/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/15 18:03:30 by swetting       #+#    #+#                */
/*   Updated: 2019/02/20 18:17:13 by swetting      ########   odam.nl         */
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
	int		total_bytes_read;

	data_read = (char *)malloc(sizeof(char) * (BUF_SIZE + 1));
	ft_bzero(data_read, BUF_SIZE);
	total_bytes_read = 0;
	while (!ft_strchr(fb->buf, '\n'))
	{
		bytes_read = read(fb->fd, data_read, BUF_SIZE);
		if (!bytes_read)
			break;
		//printf("data_read>%s\n", data_read);
		total_bytes_read += bytes_read;
		ft_repp(&fb->buf, ft_strjoin(fb->buf, data_read));
	}
	//printf("buf>%s\n", fb->buf);
	return (fb->buf);
}

char	*read_line_from_buf(fb_t *fb)
{
	char 	*line_feed;
	char	*line;

	line_feed = strchr(fb->buf, '\n');
	if (!line_feed)
		fb->buf = read_to_buf(fb);
	if (!strchr(fb->buf, '\n'))
	{
		if (!*fb->buf)
			return (NULL);
		line = fb->buf;
		fb->buf = ft_strdup("");
		return (line);
	}
	line = ft_strsub(fb->buf, 0, line_feed - fb->buf);
	ft_strncpy(fb->buf, line_feed + 1, BUF_SIZE);
	printf("line>%s\nbuf>%s\n", line, fb->buf);
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

	write(1, "Test\n", 5);
	fb = (fb_t *)malloc(sizeof(fb_t));
	fb->fd = fd;
	fb->buf = ft_strdup("");
	fb->buf = read_to_buf(fb);
	fb->next = NULL;
	return (fb);
}

int		get_next_line(const int fd, char **line)
{
	static fb_t	*fb;
	fb_t		*cur_fb;


	*line = ft_strnew(0);
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
	*line = read_line_from_buf(cur_fb);
	return (*line ? 1 : 0);
}
