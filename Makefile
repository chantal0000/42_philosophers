# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/20 12:06:09 by chbuerge          #+#    #+#              #
#    Updated: 2024/06/20 12:12:12 by chbuerge         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

#CC		= CC
CFLAGS	= -Wall -Wextra -Werror

SRC =	main.c \
		utils.c
OBJS = ${SRC:.c=.o}

all: ${NAME}

$(NAME): $(OBJS)
	cc $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cc
	cc $(CFLAGS) -c $< -o $@

clean:
	@rm -d $(OBJS)

fclean: clean
	@rm -f ${NAME}
re: flcean all

.PHONY: all clean fclean re
