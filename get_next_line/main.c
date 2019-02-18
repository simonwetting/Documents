/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: simonwetting <simonwetting@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/17 14:52:14 by simonwettin    #+#    #+#                */
/*   Updated: 2019/02/17 16:56:04 by simonwettin   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int     main(int argc, char **argv)
{
	int     fd;
	int    error;
	char    *line;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		error = get_next_line(fd, &line);
		if (error == 1)
			printf("Succesfully read a line from %s:\n%s\n", argv[1], line);
		if (error == 0)
			printf("Encountered end of file\n");
		if (error == -1)
			printf("Couldn't read file\n");
		else
			printf("Test\n");
	}
	else
		printf("Invalid amount of arguments\n");
}
