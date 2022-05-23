# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbrown <jbrown@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/19 17:27:23 by jbrown            #+#    #+#              #
#    Updated: 2022/05/23 17:17:19 by jbrown           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

CC = gcc
FLAGS = -Wall -Wextra -Werror

SRC = *.c

all: $(NAME)

$(NAME):
	$(CC) -pthread $(SRC) -o $(NAME)

bonus:

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

test1: re
	./$(NAME) 1 800 200 200

test2: re
	./$(NAME) 5 800 200 200 30

test3: re
	./$(NAME) 5 800 200 200 7

test4: re
	./$(NAME) 4 410 200 200 30

test5: re
	./$(NAME) 4 310 200 100

.PHONY: all clean fclean bonus re
