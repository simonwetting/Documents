/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/15 18:03:30 by swetting       #+#    #+#                */
/*   Updated: 2019/02/21 13:55:05 by swetting      ########   odam.nl         */
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
	void	*free_this;

	data_read = (char *)malloc(sizeof(char) * (BUF_SIZE + 1));
	ft_bzero(data_read, BUF_SIZE);
	total_bytes_read = 0;
	while (!ft_strchr(fb->buf, '\n'))
	{
		bytes_read = read(fb->fd, data_read, BUF_SIZE);
		if (!bytes_read)
			break;
		if (bytes_read < BUF_SIZE)
			data_read[bytes_read] = '\0';
		//printf("data_read>%s\n", data_read);
		total_bytes_read += bytes_read;
		free_this = fb->buf;
		fb->buf = ft_strjoin(fb->buf, data_read);
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
	line_feed = strchr(fb->buf, '\n');
	if (!line_feed)
	{
		if (!*fb->buf)
			return (NULL);
		//printf("\nbuf>%s\n\n", fb->buf);
		line = fb->buf;
		fb->buf = ft_strdup("");
		return (line);
	}
	line = ft_strsub(fb->buf, 0, line_feed - fb->buf);
	ft_strncpy(fb->buf, line_feed + 1, BUF_SIZE);
	//printf("\nline>%s\nbuf>%s\n", line, fb->buf);
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
	fb->buf = ft_strdup("");
	fb->buf = read_to_buf(fb);
	fb->next = NULL;
	return (fb);
}

int		get_next_line(const int fd, char **line)
{
	static fb_t	*fb;
	fb_t		*cur_fb;

	//printf("\nfd>%i\n", fd);
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
