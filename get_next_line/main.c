/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/17 14:52:14 by simonwettin    #+#    #+#                */
/*   Updated: 2019/03/05 11:08:18 by swetting      ########   odam.nl         */
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
			// printf("Succesfully read a line:\n%s\n\n", line);
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

// int     main(int argc, char **argv)
// {
// 	int     fd;
// 	int		i;

// 	if (argc >= 2)
// 	{
// 		i = 1;
// 		while (i < argc)
// 		{
// 			fd = open(argv[i], O_RDONLY);
// 			//printf("*****%s****%i\n", argv[i], fd);
// 			print_file(fd);
// 			close(fd);
// 			i++;
// 		}
// 	}
// 	else
// 		printf("You should specify at least 1 file\n");
// }

int		main(void)
{
	char	*line;
	int		fd[4];

	fd[0] = open("file1", O_RDONLY);
	fd[1] = open("file2", O_RDONLY);
	fd[2] = open("file3", O_RDONLY);
	fd[3] = open("20000", O_RDONLY);
	close(fd[3]);
	printf("file1 (%i)\n", fd[0]);
	printf("file2 (%i)\n", fd[1]);
	printf("file3 (%i)\n", fd[2]);
	printf("20000 (%i)\n", fd[3]);
	get_next_line(fd[0], &line);
	printf("file1: %s\n", line);
	get_next_line(fd[0], &line);
	printf("file1: %s\n", line);
	get_next_line(fd[1], &line);
	printf("file2: %s\n", line);
	get_next_line(fd[2], &line);
	printf("file3: %s\n", line);
	if (get_next_line(fd[3], &line) == -1)
		printf("Couldn't read file\nline: %s\n", line);
	get_next_line(fd[1], &line);
	printf("file2: %s\n", line);
	get_next_line(fd[0], &line);
	printf("file1\n%s\n", line);
}