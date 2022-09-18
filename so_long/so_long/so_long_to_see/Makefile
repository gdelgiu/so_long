# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperrone <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/11 06:22:28 by aperrone          #+#    #+#              #
#    Updated: 2022/03/17 08:32:00 by aperrone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
HDRS = so_long.h $(wildcard srcs/getnextline/*.h)
SRCS = $(wildcard srcs/srcs/*.c) $(wildcard srcs/getnextline/*.c)
OBJS = $(SRCS:.c=.o)
CC = gcc
FLAGS = -Wall -Wextra -Werror 
KIT = -l mlx -framework openGL -framework AppKit

all : $(NAME)

$(NAME) : 
	$(CC) $(FLAGS) $(KIT) $(SRCS) $(HDRS) && mv a.out so_long

$(OBJS): $(SRCS)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) *.tmp *.gch

fclean:	clean
	rm -f $(NAME)

check_read:
	$(CC) $(FLAGS) srcs/srcs/main.c srcs/srcs/map_handler.c srcs/srcs/map_checker.c $(HDRS) && mv a.out so_long

norm:
	norminette -R ./srcs/getnextline ./srcs/srcs

re:	fclean all

.PHONY: clean fclean norm all