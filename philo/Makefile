# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbrown <jbrown@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/13 08:55:27 by jbrown            #+#    #+#              #
#    Updated: 2022/05/20 16:20:33 by jbrown           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc
FLAGS = -Wall -Wextra -Werror

SRC = *.c

HELPFUL_MESSAGE = echo "Arguments for philo are:\n\
						num_of_philos\n\
						time_to_die\n\
						time_to_eat\n\
						time_to_sleep\n\
						num_of_times_to_eat (optional)\n\
						For example, try:\n\
						./philo 5 800 200 200 7"
REMOVE_MESSAGE = echo "Removing philo program"

all: $(NAME)

$(NAME):
	@$(CC) $(FLAGS) -pthread $(SRC) -o $(NAME)
	@$(HELPFUL_MESSAGE)

bonus:

clean:
	@rm -f $(NAME)
	@$(REMOVE_MESSAGE)

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
