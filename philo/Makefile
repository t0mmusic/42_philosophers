# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbrown <jbrown@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/13 08:55:27 by jbrown            #+#    #+#              #
#    Updated: 2022/05/13 08:58:20 by jbrown           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc
FLAGS = -Wall -Wextra -Werror

SRC = *.c

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) -pthread $(SRC) -o $(NAME)

bonus:

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean bonus re
