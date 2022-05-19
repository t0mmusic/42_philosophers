# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbrown <jbrown@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/13 08:55:27 by jbrown            #+#    #+#              #
#    Updated: 2022/05/19 16:09:12 by jbrown           ###   ########.fr        #
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

test1: re
	./$(NAME) 1 800 200 200

test2: re
	./$(NAME) 5 800 200 200 100

test3: re
	./$(NAME) 5 800 200 200 7

test4: re
	./$(NAME) 4 410 200 200 100

test5: re
	./$(NAME) 4 310 200 100

.PHONY: all clean fclean bonus re
