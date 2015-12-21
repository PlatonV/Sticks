/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 12:35:57 by vplaton           #+#    #+#             */
/*   Updated: 2015/12/21 13:12:27 by vplaton          ###   ########.fr       */
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
		if (ft_atoi(str) <= 0)
		{
			write(2, "ERROR\n", 6);
			return (0);
		}
		if (!result)
			result = create_node(ft_atoi(str));
		else
			append_node(&result, ft_atoi(str));
	}
	return (result);
}

t_double_list		*read_list2(void)
{
	t_double_list	*result;
	char			*str;

	result = NULL;
	while (get_next_line(0, &str))
	{
		if (str[0] == '\0')
			return (result);
		if (ft_atoi(str) <= 0)
		{
			write(2, "ERROR\n", 6);
			return (0);
		}
		if (!result)
			result = create_node(ft_atoi(str));
		else
			append_node(&result, ft_atoi(str));
	}
	return (result);
}
