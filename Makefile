# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MAKEFILE                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/09 12:28:29 by jvanden-          #+#    #+#              #
#    Updated: 2021/08/09 12:36:38 by jvanden-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
INCL		=	./inc/

CFLAGS		= -I $(INCL) $(FLAGS)

NAME	=	push_swap

### PATH ###

SRCS_PATH	=	src/

SRCS_PSWAP	=	push_swap.c

SRCS_PSWAP2	=	$(addprefix $(SRCS_PATH), $(SRCS_PSWAP))

OBJ_PSWAP	=	$(SRCS_PSWAP2:.c=.o)

OBJ_PATH	=	$(OBJ_PSWAP)

######### RULES #######

all : $(NAME)

$(NAME) : $(OBJ_PSWAP)
	@$(CC) -o $(NAME) $(OBJ_PSWAP) $(CFLAGS)


clean:
	@/bin/rm -rf $(OBJ_PATH)
	@echo "\033[31mObjects files \033[1;31m$(OBJS_LIST)\033[1;0m\033[31m removed.\033[0m"

fclean: clean
	@/bin/rm -rf $(NAME)
	@echo "\033[31mBin \033[1;31m$(NAME)\033[1;0m\033[31m removed.\033[0m"

re: fclean all


.PHONY: all re clean fclean libs


