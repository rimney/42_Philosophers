# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rimney <rimney@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/05 20:18:35 by rimney            #+#    #+#              #
#    Updated: 2022/04/05 20:30:09 by rimney           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers
SRCS = philosophers.c \
		philosophers_utils.c \
		philosophers_utils01.c \

CC = gcc
FLAGS = -Wall -Wextra -Werror

$(NAME) :
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)
all : $(NAME)
clean :
	rm -f $(NAME)
fclean :
	rm -f $(NAME)
re : fclean all

.PHONY : all clean fclean re
