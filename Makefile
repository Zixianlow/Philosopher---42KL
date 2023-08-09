# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 17:48:55 by lzi-xian          #+#    #+#              #
#    Updated: 2023/08/09 21:30:34 by lzi-xian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo
BONUS_NAME	=	philo_bonus
SRCS		=	main.c				\
				philo_action.c		\
				philo_death.c		\
				philo_init.c		\
				philo_utils.c
BONUS_SRCS	=	bonus/main_bonus.c			\
				bonus/philo_action_bonus.c	\
				bonus/philo_init_bonus.c	\
				bonus/philo_utils_bonus.c
ARCR		= 	ar cr
RMRF		=	rm -rf
CFLAGS		=	-Wall -Wextra -Werror
GCC			=	gcc

$(NAME):
	${GCC} ${CFLAGS} ${SRCS} -o $(NAME)

$(BONUS_NAME):
	${GCC} ${CFLAGS} ${BONUS_SRCS} -o ${BONUS_NAME}

bonus:	$(BONUS_NAME)

all:	$(NAME)

clean:
	${RMRF} $(NAME)

fclean:	clean
	${RMRF} $(BONUS_NAME)

re:	fclean all
