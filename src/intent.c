/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 18:57:27 by                   #+#    #+#             */
/*   Updated: 2015/12/20 21:43:12 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "alum.h"

void	init(t_double_list *lst)
{
	g_intent = (char*)malloc(list_size(lst));
}

void	gen_intent(t_double_list *ls)
{
	int index;
	
	index = 0;
	g_intent[list_size(ls) - 1] = 0;
	while (ls->next)
	{
		ls = ls->next;
		g_intent[index++] = (ls->value % 4 == 1);
	}
}
