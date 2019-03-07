/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: simonwetting <simonwetting@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/06 10:30:21 by swetting       #+#    #+#                */
/*   Updated: 2019/03/07 11:20:39 by simonwettin   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>



int		read_next_tetrimino(int fd)
{
	char	tetrimino[4][2];
	char	*data_read;
	int 	i;
	char	pos[2];
	int		pos_count;

	if (read(fd, data_read, 21) < 21)
		return (-1);
	pos[0] = 0;
	pos[1] = 0;
	pos_count = 0;
	while (i < 21)
	{
		if (data_read[i] == '#')
			tetrimino[pos_count] = pos;
		
	}
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
