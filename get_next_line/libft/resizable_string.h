/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   resizable_string.h                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/22 15:43:36 by swetting       #+#    #+#                */
/*   Updated: 2019/02/22 16:28:53 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESIZABLE_STRING
# define RESIZABLE_STRING
#include "libft.h"

typedef struct	resizable_string
{
	char		*str;
	size_t		size;
}				rstr_t;

rstr_t	*new_rstr(const char *str);
rstr_t	*new_rstrn(const char *str, size_t len);
void	rep_rstr(rstr_t **old, rstr_t *new);
rstr_t	*append_rstr(rstr_t **rstr, const char *str);

#endif