# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    Created: 2022/06/27 12:04:01 by fcoutinh          #+#    #+#              #
#    Updated: 2022/06/27 14:03:35 by fcoutinh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## Vars
CC	= gcc
NAME	= a.out
CFLAGS	= -Wall -Wextra  -I
INCLUDE	= include

## Sources
SRCS	= $(wildcard src/*.c)
OBJS	= $(SRCS:.c=.o)

## Rules
all:	 $(NAME)

$(NAME): $(OBJS)
ifeq ("$(src/libstructs.a)", "")
	@make -C libs
	@mv libs/libstructs.a src/
endif
	$(CC) $^ -Lsrc -lstructs -o a.out $(CFLAGS) $(INCLUDE)
	@make clean

%.o:	%.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@ 

clean:
	@make clean -C libs
	@rm -f $(OBJS)

fclean:
	@make fclean -C libs
	@rm -f $(OBJS) $(NAME) src/libstructs.a

re:	fclean $(NAME)

relibs: fclean	
	@make re -C libs
	@mv libs/libstructs.a src/
	$(CC) $(SRCS) -Lsrc -lstructs -o a.out $(CFLAGS) $(INCLUDE)
	@make clean

.PHONY:	all clean fclean re relibs
