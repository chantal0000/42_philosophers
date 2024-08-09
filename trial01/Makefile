# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/20 12:06:09 by chbuerge          #+#    #+#              #
#    Updated: 2024/08/09 12:32:21 by chbuerge         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

#CC		= CC
CFLAGS	= -Wall -Wextra -Werror

SRC =	main.c \
		utils.c \
		error.c \
		ft_atoi.c
OBJS = ${SRC:.c=.o}

all: ${NAME}

$(NAME): $(OBJS)
	cc $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cc
	cc $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
