/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 13:05:25 by vplaton           #+#    #+#             */
/*   Updated: 2015/12/21 13:13:12 by vplaton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum.h"

int					g_index;

int					calculate_choice(t_double_list *lst)
{
	int		choice;

	if (!g_intent[g_index])
	{
		choice = lst->value % 4 - 1;
		if (choice == -1)
			return (3);
		if (choice == 0)
			return (1);
	}
	else
	{
		choice = lst->value % 4;
		if (choice == 0)
			return (1);
	}
	return (choice);
}

void				player_move(t_double_list *lst)
{
	int			choice;
	char		*answer;

	get_next_line(1, &answer);
	choice = ft_atoi(answer);
	while (choice < 1 || choice > 3 || lst->value - choice < 0)
	{
		ft_putendl("Please enter a valid choice!");
		get_next_line(1, &answer);
		choice = ft_atoi(answer);
	}
	lst->value -= choice;
	if (lst->value == 0 && !lst->next)
	{
		ft_putendl("You lose!");
		exit(0);
	}
}

void				my_move(t_double_list *lst)
{
	int		choice;

	choice = calculate_choice(lst);
	ft_putstr("I chose ");
	ft_putnbr(choice);
	ft_putendl("");
	lst->value -= choice;
	if (lst->value == 0 && !lst->next)
	{
		ft_putendl("You win!");
		exit(0);
	}
}

void				run_game(t_double_list *lst)
{
	while (lst->value)
	{
		print_list(lst);
		ft_putendl("How many sticks do you want to remove?");
		player_move(lst);
		if (lst->value == 0 && lst->next)
		{
			lst = lst->next;
			g_index++;
		}
		my_move(lst);
		if (lst->value == 0 && lst->next)
		{
			lst = lst->next;
			g_index++;
		}
	}
}

int					main(int argc, char **argv)
{
	int				fd;
	t_double_list	*list;

	list = NULL;
	if (argc == 1)
		list = read_list2();
	else if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		list = read_list(fd);
	}
	if (list)
	{
		init(list);
		gen_intent(list);
		run_game(list);
	}
	return (0);
}
