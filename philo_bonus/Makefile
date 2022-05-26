# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbrown <jbrown@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/19 17:27:23 by jbrown            #+#    #+#              #
#    Updated: 2022/05/26 10:01:19 by jbrown           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

CC = gcc
FLAGS = -Wall -Wextra -Werror

SRC = *.c

HELPFUL_MESSAGE = echo "Arguments for philo bonus are:\n\
						num_of_philos\n\
						time_to_die\n\
						time_to_eat\n\
						time_to_sleep\n\
						num_of_times_to_eat (optional)\n\
						For example, try:\n\
						./philo 5 800 200 200 7"
REMOVE_MESSAGE = echo "Removing philo_bonus program"

all: $(NAME)

$(NAME):
	@$(CC) -pthread $(SRC) -o $(NAME)
	@$(HELPFUL_MESSAGE)

bonus: all

clean:
	@rm -f $(NAME)
	@$(REMOVE_MESSAGE)

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
