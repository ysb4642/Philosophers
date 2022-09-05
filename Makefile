# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seyeo <seyeo@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/05 18:19:42 by seyeo             #+#    #+#              #
#    Updated: 2022/09/05 18:22:59 by seyeo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo
CC 			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM 			= rm -rf

SRCS		= main.c \
			  init.c \
			  philo_action.c \
			  utils_philo.c \
			  utils.c \
			  
OBJS		= $(SRCS:%.c=%.o)

all    : $(NAME)
.PHONY : all

$(NAME) : ${OBJS}
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
		$(RM) $(OBJS)
.PHONY: clean

fclean: clean
		$(RM) $(NAME) $(OBJS)
.PHONY: fclean

re: $(MAKE) fclean
	$(MAKE) all
.PHONY: re