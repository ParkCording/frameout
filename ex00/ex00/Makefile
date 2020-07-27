# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minskim <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/14 22:33:34 by minskim           #+#    #+#              #
#    Updated: 2020/06/29 23:37:58 by minskim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAG = -Wall -Wextra -Werror
NAME = rush-02
OBJECT = $(SRC:.c=.o)
SRC = ft_calculate_div_set.c main.c ft_read_util2.c ft_read_util.c ft_utils.c ft_read.c ft_dict_parsing.c
INCS = includes

all : $(NAME)

$(NAME) : $(OBJECT)
	${CC} ${FLAG} -o $(NAME) $(OBJECT)

.c.o :
	$(CC) $(FLAG) -c $< -o $@ -I ${INCS}

clean :
	rm -f $(OBJECT)

fclean : clean
	rm -f $(NAME)

re : fclean all
