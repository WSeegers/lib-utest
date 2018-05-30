# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/30 03:17:16 by wseegers          #+#    #+#              #
#    Updated: 2018/05/30 05:13:51 by wseegers         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libutest.a
CC = clang
CFLAGS = -Werror -Wall -Wextra -I include

SRC = add_test.c create_test.c create_unit.c get_result.c kill_timer.c\
	  run_test.c run_unit.c

BIN_PATH = bin
BIN := $(addprefix $(BIN_PATH)/, $(SRC:%.c=%.o))
DEP := $(BIN:%.o=%.d)

all : $(NAME)

$(NAME) : $(BIN)
	ar rc $@ $?
	ranlib $@

$(BIN_PATH)/%.o : %.c
	mkdir -p $(BIN_PATH)
	$(CC) $(CFLAGS) -MMD -o $@ -c $<

-include $(DEP)

clean : 
	rm -rf $(BIN_PATH)

fclean : clean
	rm -f $(NAME)

re : fclean all
