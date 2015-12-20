/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 15:27:20 by                   #+#    #+#             */
/*   Updated: 2015/12/20 19:33:45 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum.h"

t_double_list		*create_node(int value)
{
	t_double_list	*result;

	result = (t_double_list*)malloc(sizeof(t_double_list));
	result->value = value;
	result->next = NULL;
	result->prev = NULL;
	return (result);
}

void				append_node(t_double_list **lst, int value)
{
	t_double_list	*result;

	result = create_node(value);
	result->next = *lst;
	(*lst)->prev = result;
	*lst = result;
}

t_uint				list_size(t_double_list *lst)
{
	t_uint		result;

	result = 0;
	while (lst)
	{
		result++;
		lst = lst->next;
	}
	return (result);
}

void				print_list(t_double_list *lst)
{
	while (lst->next)
		lst = lst->next;
	while (lst && lst->value != 0)
	{
		ft_putnbr(lst->value);
		ft_putendl("");
		lst = lst->prev;
	}
}
