/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/20 14:18:22 by swetting       #+#    #+#                */
/*   Updated: 2019/02/22 16:30:35 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "resizable_string.h"
#include "libft/ft_strchr.c"
#include "libft/ft_strlen.c"
#include "libft/ft_strdup.c"
#include <stdio.h>

int		main(void)
{
	rstr_t	*rstr;

	rstr = new_rstr("test");
	printf("rstr->str = %s\n", rstr->str);
	append_rstr(&rstr, "test2");
	printf("rstr->str = %s\n", rstr->str);
	append_rstr(&rstr, "test3");
	printf("rstr->str = %s\n", rstr->str);
}