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
CC			= gcc
NAME		= a.out
LIB_NAME	= libinode.a
CFLAGS		= -Wall -Wextra -Werror -I
INCLUDE		= include
VF			?= 0

## Sources
LIB_SRCS	= $(wildcard libs/*/*.c)
SRCS		= $(wildcard src/*.c)
LIB_OBJS	= $(LIB_SRCS:.c=.o)
OBJS		= $(SRCS:.c=.o)

## Rules
all:	 $(NAME)

$(NAME): $(LIB_OBJS) $(OBJS)
	@ar rcs src/$(LIB_NAME) $(LIB_OBJS)
	@echo "> list and Tree libs compiled;"
ifeq ($(VF), 0)
	@$(CC) $^ -Lsrc -linode -o a.out $(CFLAGS) $(INCLUDE)
else
	$(CC) $^ -Lsrc -linode -o a.out $(CFLAGS) $(INCLUDE)
endif	
	@echo "> Executable file done;"
	@make clean --no-print-directory

%.o:	%.c
ifeq ($(VF), 0)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
else
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
endif

clean:
	@rm -f $(LIB_OBJS) $(OBJS)
	@echo "> Object files deleted;"

fclean:
	@make clean --no-print-directory
	@rm -f $(NAME) src/$(LIB_NAME)
	@echo "> Executable file and static libs deleted;"

re:	fclean $(NAME)

.PHONY:	all clean fclean re