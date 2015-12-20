# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vplaton <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/16 11:07:24 by vplaton           #+#    #+#              #
#*   Updated: 2015/12/20 16:43:00 by                  ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = alum1
SRCS = src/*.c
INCLUDES = includes/
OBJ = *.o

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -I $(INCLUDES) -c $(SRCS)
	gcc -o $(NAME) $(OBJ) -L libft/ -lft

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
