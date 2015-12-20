/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 15:03:30 by                   #+#    #+#             */
/*   Updated: 2015/12/20 21:42:59 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "alum.h"

int					g_index;

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
	int		choice;

	if (!g_intent[g_index])
	{
		ft_putendl("I dont want to finish ");
		choice = lst->value % 4 - 1;
		if (choice == -1)
			return (3);
		if (choice == 0)
			return (1);
	}
	else
	{
		ft_putendl("I want to finish ");
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
	while (lst->value)
	{
		ft_putendl("--------------------------------------");
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

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		list = read_list(fd);
		init(list);
		gen_intent(list);
		run_game(list);
	}
	return (0);
}
