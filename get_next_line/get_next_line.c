/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/15 18:03:30 by swetting       #+#    #+#                */
/*   Updated: 2019/02/18 17:27:06 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char	*read_to_buf(int fd, char *remainder)
{
	char	*result;
	int		bytes_read;
	char	*buf;
	void	*free_this;


	result = strdup(remainder);
	bytes_read = 1;
	buf = NULL;
	while (ft_strchr(result, '\n') == NULL && bytes_read)
	{
		if (buf == NULL)
		{
			buf = (char *)malloc(sizeof(char) * BUF_SIZE + 1);
			ft_bzero(buf, BUF_SIZE);
		}
		bytes_read = read(fd, buf, BUF_SIZE);
		free_this = result;
		result = ft_strjoin(result, buf);
		free(free_this);
	}
	free (buf);
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
	fb->buf = read_to_buf(fd, "");
	fb->next = NULL;
	return (fb);
}

char	*next_line_to_char(fb_t *buffer)
{
	char	*line;
	char	*buf;
	char	*next_newline;

	buf = buffer->buf;
	next_newline = strchr(buf, '\n');
	if (next_newline == NULL)
	{
		buf = read_to_buf(buffer->fd, buf);
		next_newline = strchr(buf, '\n');
	}
	else
		printf("newline:%c", *next_newline);
	line = ft_strsub(buf, 0, next_newline - buf);
	printf("len>%zu\n", ft_strlen(next_newline));
	if (ft_strlen(next_newline) > 1)
	{
		buffer->buf = ft_strdup(next_newline + 1);
		free(buf);
		return (line);
	}
	else
		return (NULL);	
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
	return (*line? 1 : 0);
}
