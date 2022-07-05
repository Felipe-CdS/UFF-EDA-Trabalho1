# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcoutinh <felipe_coutinho@id.uff.br>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/27 12:04:01 by fcoutinh          #+#    #+#              #
#    Updated: 2022/07/04 17:54:30 by fcoutinh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## Vars
CC	= gcc
NAME	= libstructs.a
CFLAGS	= -Wall -Wextra -Werror -I
INCLUDE	= ../include

## Sources
SRCS	= $(wildcard */*.c)
OBJS	= $(SRCS:.c=.o)

## Rules
all:	 $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "> list and Tree libs compiled;"

%.o:	%.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@ 

clean:
	@rm -f $(OBJS)
	@echo "> clean done;"

fclean:
	@rm -f $(OBJS) $(NAME) 
	@echo "> fclean done;"

re:	fclean $(NAME)

.PHONY:	all clean fclean re
