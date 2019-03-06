/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/06 10:30:21 by swetting       #+#    #+#                */
/*   Updated: 2019/03/06 12:52:55 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>



int		read_next_tetrimino(int fd)
{
	
}

int		read_tetriminos(char *filename)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	
}

int		main(int argc, char **argv)
{

}
