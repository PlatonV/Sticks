/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 13:05:52 by vplaton           #+#    #+#             */
/*   Updated: 2015/12/21 13:07:32 by vplaton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALUM_H
# define ALUM_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
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
char						*g_intent;

t_double_list				*create_node(int value);
void						append_node(t_double_list **lst, int value);
t_uint						list_size(t_double_list *lst);
void						print_list(t_double_list *lst);
t_double_list				*read_list(int fd);
t_double_list				*read_list2(void);
void						init(t_double_list *lst);
void						gen_intent(t_double_list *lst);

#endif
