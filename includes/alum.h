/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 15:05:02 by                   #+#    #+#             */
/*   Updated: 2015/12/20 18:03:09 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALUM_H
# define ALUM_H

# include <fcntl.h>
# include <stdlib.h>
# include "libft.h"
# include "get_next_line.h"

typedef unsigned int		t_uint;

typedef struct				s_double_list
{
	int						value;
	struct s_double_list	*next;
	struct s_double_list	*prev;
}							t_double_list;

long						g_count;
unsigned char				*g_intent;

t_double_list				*create_node(int value);
void						append_node(t_double_list **lst, int value);
t_uint						list_size(t_double_list *lst);
void						print_list(t_double_list *lst);

#endif
