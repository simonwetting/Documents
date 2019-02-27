/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/17 14:52:14 by simonwettin    #+#    #+#                */
/*   Updated: 2019/02/27 16:37:04 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int		print_file(int fd)
{
	int 	error;
	char	*line;
	char	read_once;
	//int		i = 0;

	error = 1;
	read_once = 0;
	while (error > 0)
	//while (i++ < 100)
	{
		error = get_next_line(fd, &line);
		if (error == 1)
		{
			if (read_once)
				printf("\n");
			else
				read_once = 1;
			printf("%s", line);
			//printf("Succesfully read a line:\n%s\n\n", line);
		}
		if (error == 0)
		{
			//printf("Reached end of file.\n");
			return (0);
		}
		if (error == -1)
		{
			printf("Couldn't read next line\n");
			return (-1);
		}
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
			//printf("*****%s*****\n", argv[i]);
			fd = open(argv[i], O_RDONLY);
			print_file(fd);
			close(fd);
			i++;
		}
	}
	else
		printf("You should specify at least 1 file\n");
}
