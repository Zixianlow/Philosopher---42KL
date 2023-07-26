# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 17:48:55 by lzi-xian          #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2023/07/26 16:11:02 by lzi-xian         ###   ########.fr        #
=======
#    Updated: 2023/04/28 14:54:58 by lzi-xian         ###   ########.fr        #
>>>>>>> parent of c59d58f... Final update
#                                                                              #
# **************************************************************************** #

NAME		=	philo
BONUS_NAME	=	philo_bonus
SRCS		=	main.c				\
				philo_action.c		\
				philo_init.c		\
				philo_utils.c
BONUS_SRCS	=	bon/main_bonus.c			\
				bon/philo_action_bonus.c	\
				bon/philo_init_bonus.c	\
				bon/philo_utils_bonus.c
ARCR		= 	ar cr
RMRF		=	rm -rf
CFLAGS		=	-Wall -Wextra -Werror
GCC			=	gcc

$(NAME):
	${GCC} ${CFLAGS} ${SRCS} -o $(NAME)

$(BONUS_NAME):
	${GCC} ${CFLAGS} ${BONUS_SRCS} -o ${BONUS_NAME} -fsanitize=thread -g3

thread:
	${GCC} ${CFLAGS} ${BONUS_SRCS} -o ${BONUS_NAME} -fsanitize=thread -g3

bonus:	$(BONUS_NAME)

all:	$(NAME)

clean:
	${RMRF} $(NAME)

fclean:	clean
	${RMRF} $(BONUS_NAME)

re:	fclean bonus