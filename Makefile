# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jalwahei <jalwahei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/25 15:37:38 by jalwahei          #+#    #+#              #
#    Updated: 2022/12/12 15:15:03 by jalwahei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = client
NAME1 = server
SRC = client.c inc/ft_atoi.c
SRC1 = server.c printf/libftprintf.a
OBJ = $(SRC:.c=.o)
OBJ1 = $(SRC1:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror


all: $(NAME) $(NAME1)

$(NAME) : $(OBJ)
	@make -C ./printf
	$(CC) $(CFLAGS) $(OBJ)  -o $(NAME) printf/libftprintf.a -o $@

$(NAME1) : $(OBJ1)
	$(CC) $(CFLAGS) $(OBJ1) -o $(NAME1) printf/libftprintf.a -o $@

clean:
		rm -f *.o
		rm -f ./inc/*.o
		rm -f ./printf/*.o

fclean: clean
		rm -f client server
		rm -f ./printf/libftprintf.a
re: fclean all