/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 15:03:30 by                   #+#    #+#             */
/*   Updated: 2015/12/20 18:41:58 by                  ###   ########.fr       */
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

int					calculate_choice(t_double_list *lst)
{
	int		index;

	index = 0;
	while (lst->next)
	{
		lst = lst->next;
		index++;
	}
	if (!g_intent[index])
		return (lst->value % 4);
	else
		return (lst->value % 4 - 1 > 0 ? lst->value % 4 - 1 : 1);
}

void				player_move(t_double_list *lst)
{
	int		choice;
	char		*answer;

	get_next_line(1, &answer);
	choice = ft_atoi(answer);
	lst->value -= choice;
}

void				my_move(t_double_list *lst)
{
	int		choice;

	choice = calculate_choice(lst);
	ft_putendl("I chose ");
	ft_putnbr(choice);
	ft_putendl("");
	lst->value -= choice;
}

void				run_game(t_double_list *lst)
{
	while (lst->next)
	{
		ft_putendl("--------------------------------------");
		print_list(lst);
		ft_putendl("How many sticks do you want to remove?");
		player_move(lst);
		if (lst->value == 0)
			lst = lst->next;
		my_move(lst);
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
