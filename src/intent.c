/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 13:13:17 by vplaton           #+#    #+#             */
/*   Updated: 2015/12/21 13:14:58 by vplaton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum.h"

void	init(t_double_list *lst)
{
	g_intent = (char*)malloc(list_size(lst));
}

void	gen_intent(t_double_list *ls)
{
	int index;

	index = list_size(ls) - 1;
	g_intent[index--] = 0;
	while (ls->next)
		ls = ls->next;
	while (ls->prev)
	{
		if (g_intent[index + 1])
		{
			if (ls->value % 4 == 0)
				g_intent[index] = 1;
			else
				g_intent[index] = 0;
		}
		else
		{
			if (ls->value % 4 == 1)
				g_intent[index] = 1;
			else
				g_intent[index] = 0;
		}
		ls = ls->prev;
		index--;
	}
}
