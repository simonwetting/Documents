/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   speed_test.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/01 14:46:34 by swetting       #+#    #+#                */
/*   Updated: 2019/03/01 14:51:03 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

void		print_file(int fd)
{
	char	*line;

	while (get_next_line(fd, &line) == 1);
        //printf("%s\n", line);
}

int     main(int argc, char **argv)
{
	int     fd;

	if (argc == 2)
	{
        fd = open(argv[1], O_RDONLY);
        //printf("*****%s****%i\n", argv[i], fd);
        print_file(fd);
        close(fd);
	}
	else
		printf("You should specify 1 file\n");
}