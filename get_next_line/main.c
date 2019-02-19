/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/17 14:52:14 by simonwettin    #+#    #+#                */
/*   Updated: 2019/02/18 16:53:40 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int		print_file(int fd)
{
	int 	error;
	char	*line;
	error = get_next_line(fd, &line);
	while (error > 0)
	{
		if (error == 1)
			printf("Succesfully read a line:\n%s\n\n", line);
		if (error == 0)
		{
			printf("Reached end of file.\n");
			return (0);
		}
		if (error == -1)
		{
			printf("Couldn't read next line\n");
			return (-1);
		}
		error = get_next_line(fd, &line);
	}
	return (0);
}

int     main(int argc, char **argv)
{
	int     fd;
	int		i;

	if (argc >= 2)
	{
		i = 1;
		while (i < argc)
		{
			fd = open(argv[1], O_RDONLY);
			print_file(fd);
			close(fd);
			i++;
		}
	}
	else
		printf("You should specify at least 1 file\n");
}
