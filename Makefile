# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jopaning <jopaning@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/29 10:15:39 by jopaning          #+#    #+#              #
#    Updated: 2019/06/24 17:26:55 by jopaning         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

HEADERS = fillit.h

SRC =	ft_board.c \
	ft_block.c \
	ft_bzero.c \
	ft_check.c \
	ft_check_extension.c \
	ft_magic.c \
	ft_memset.c \
	ft_putchar.c \
	ft_putendl.c \
	main.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra

CC = @gcc $(CFLAGS)

all: $(NAME)

$(NAME) : $(OBJ) $(HEADERS)
	@$(CC) $(OBJ) -o $(NAME)

.%.o: .%.c
	@$(CC) -c $(SRC)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
