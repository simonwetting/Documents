/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/17 14:50:23 by simonwettin    #+#    #+#                */
/*   Updated: 2019/02/28 10:19:55 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# include "libft/libft.h"
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32

typedef struct  		file_buffer
{
	int					fd;
	char				*buf;
	int					index;
	struct file_buffer	*next;
}						fb_t;

int						get_next_line(const int fd, char **line);
#endif