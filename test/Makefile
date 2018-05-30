# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/30 03:41:36 by wseegers          #+#    #+#              #
#    Updated: 2018/05/30 05:15:57 by wseegers         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = run_test

CC = clang
CFLAGS = -Werror -Wall -Wextra -I ../include 
LIB = -L ../ -lutest

SRC = test_utest.c

BIN_PATH = bin
BIN := $(addprefix $(BIN_PATH)/, $(SRC:%.c=%.o))
DEP := $(BIN:%.o=%.d)


all : ../libutest.a $(NAME)

../libutest.a : 
	make -C ../

$(NAME) : $(BIN)
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

$(BIN_PATH)/%.o : %.c
	mkdir -p $(BIN_PATH)
	$(CC) $(CFLAGS) -MMD -o $@ -c $<

-include $(DEP)

clean : 
	rm -rf $(BIN_PATH)
	rm -f result.log

fclean : clean
	rm -f $(NAME)

re : fclean all

