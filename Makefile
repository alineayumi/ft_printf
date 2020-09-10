# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afukuhar <afukuhar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/16 10:52:40 by afukuhar          #+#    #+#              #
#    Updated: 2020/09/09 14:29:24 by afukuhar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

CFILES = ./libft/ft*.c ft*.c
OFILES = ft*.o
INCLUDES = ./

all:	$(NAME)

$(NAME):
		@$(CC) $(CFLAGS) -I$(INCLUDES) -c $(CFILES)
		@ar rc $(NAME) $(OFILES)
		@ranlib $(NAME)

bonus: re

clean:
		@/bin/rm -f $(OFILES)

fclean: clean
		@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean
