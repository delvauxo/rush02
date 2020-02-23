# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: odelvaux <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/22 16:42:40 by odelvaux          #+#    #+#              #
#    Updated: 2020/02/23 23:04:00 by odelvaux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OUT = rush-02
SRC = main.c helper.c helper2.c error.c convert.c open_read.c
OBJ = $(SRC:.c=.o)

CC = gcc
CCFLAGS = -Wall -Werror -Wextra

.PHONY: all
all: $(OUT)

$(OUT): $(OBJ)
	$(CC) $(CCFLAGS) $(OBJ) -o $(OUT)

%.o: %.c mylib.h
	$(CC) $(CCFLAGS) -c $< -o $@

.PHONY: fclean
fclean:
	rm -f $(OBJ) $(OUT)
