/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 12:35:57 by vplaton           #+#    #+#             */
/*   Updated: 2015/12/21 12:43:47 by vplaton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum.h"

t_double_list		*read_list(int fd)
{
	t_double_list	*result;
	char			*str;

	result = NULL;
	while (get_next_line(fd, &str))
	{
		if (!result)
			result = create_node(ft_atoi(str));
		else
			append_node(&result, ft_atoi(str));
	}
	return (result);
}

t_double_list		*read_list2()
{
	t_double_list	*result;
	char			*str;

	result = NULL;
	while (get_next_line(0, &str))
	{
		if (str[0] == '\0')
			return (result);
		if (!result)
			result = create_node(ft_atoi(str));
		else
			append_node(&result, ft_atoi(str));
	}
	return (result);
}
