# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbrown <jbrown@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/26 09:40:16 by jbrown            #+#    #+#              #
#    Updated: 2022/05/26 10:05:44 by jbrown           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

BONUS = philo_bonus

CC = gcc
FLAGS = -Wall -Wextra -Werror

SRC = *.c

all: $(NAME)

$(NAME):
	@$(MAKE) -C ./$(NAME)
	@$(HELPFUL_MESSAGE)

bonus: $(BONUS)

$(BONUS): all
	@$(MAKE) -C ./$(BONUS)

clean:
	@$(MAKE) clean -C ./$(NAME)
	@$(MAKE) clean -C ./$(BONUS)

fclean: clean

re:
	@$(MAKE) fclean all -C ./$(NAME)

git:
	@clear
	@git add .
	@echo "commit msg" 
	@read COMMIT; \
	git commit -m "$$COMMIT"; \
	git push;

.PHONY: all clean fclean bonus re git