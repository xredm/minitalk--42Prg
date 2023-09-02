# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xredm <xredm@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/02 14:28:44 by xredm             #+#    #+#              #
#    Updated: 2023/09/02 16:09:55 by xredm            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_S = server
NAME_C = client

SRC_S = server.c
SRC_C = client.c

LIBFT_FOLDER = libft
libft = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(libft) $(NAME_S) $(NAME_C)

$(libft):
	@make -C $(LIBFT_FOLDER)

$(NAME_S):
	$(CC) $(CFLAGS) $(SRC_S) libft/libft.a -o $(NAME_S)

$(NAME_C):
	$(CC) $(CFLAGS) $(SRC_C) libft/libft.a -o $(NAME_C)

%.o: %.c
	$(CC) $(CFLAGS) -c $< $@

clean: 
	rm $(NAME_C) $(NAME_S)
	@make clean -C $(LIBFT_FOLDER)

fclean: clean
	@make fclean -C $(LIBFT_FOLDER)

re: fclean all

.PHONY: all clean fclean re
