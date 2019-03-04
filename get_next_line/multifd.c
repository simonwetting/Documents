/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   multifd.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: simonwetting <simonwetting@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/04 10:33:05 by simonwettin    #+#    #+#                */
/*   Updated: 2019/03/04 10:48:29 by simonwettin   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.c"

int		main(void)
{
	int 	fd[4];
	char	*line;

	fd[0] = open("file1", O_RDONLY);
	fd[1] = open("file2", O_RDONLY);
	fd[2] = open("file3", O_RDONLY);
	fd[3] = open("2000", O_RDONLY);
	close(fd[3]);
	get_next_line(fd[0], &line);
	printf("line>%s\n", line);
	get_next_line(fd[1], &line);
	// printf("line>%s\n", line);
	// get_next_line(fd[2], &line);
	// printf("line>%s\n", line);
	// get_next_line(fd[3], &line);
	// printf("line>%s\n", line);
}