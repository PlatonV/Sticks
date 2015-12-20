/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 15:03:30 by                   #+#    #+#             */
/*   Updated: 2015/12/20 18:03:09 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "alum.h"

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

void				run_game(t_double_list *lst)
{
	char		*answer;
	int			choice;

	while (lst->next)
	{
		ft_putendl("--------------------------------------");
		print_list(lst);
		ft_putendl("How many sticks do you want to remove?");
		get_next_line(1, &answer);
		choice = ft_atoi(answer);
		lst->value -= choice;
		if (lst->value == 0)
			lst = lst->next;
	}
}

int					main(int argc, char **argv)
{
	int				fd;
	t_double_list	*list;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		list = read_list(fd);
		run_game(list);
	}
	return (0);
}
