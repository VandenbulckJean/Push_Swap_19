# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/09 12:28:29 by jvanden-          #+#    #+#              #
#    Updated: 2021/08/10 18:31:11 by jvanden-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
INCL		=	./inc/

CFLAGS		= -I $(INCL) $(FLAGS)

NAME	=	push_swap

### PATH ###

SRCS_PATH	=	src/

SRCS_PSWAP	=	push_swap.c \
				parsing.c \
				exit.c \
				algorithm.c \
				algorithm_functions/count_rotation_to_sorted.c \
				algorithm_functions/find_best_insertion.c \
				algorithm_functions/stack_store_top_three_max.c \
				functions/count_element_char_array.c \
				functions/ft_atoi.c \
				functions/ft_isdigit.c \
				functions/ft_max \
				functions/ft_min.c \
				functions/ft_putchar.c \
				functions/ft_putnbr.c \
				functions/ft_strcmp.c \
				functions/ft_strlen.c \
				functions/ft_strsplit.c \
				structure/insertion_operation.c \
				structure/insertion.c \
				structure/list.c \
				structure/stack_check.c \
				structure/stack_do_n_print_operation.c \
				structure/stack_management.c \
				structure/stack_operation.c \
				

SRCS_PSWAP2	=	$(addprefix $(SRCS_PATH), $(SRCS_PSWAP))

OBJ_PSWAP	=	$(SRCS_PSWAP2:.c=.o)

OBJ_PATH	=	$(OBJ_PSWAP)

######### RULES #######

all : $(NAME)

$(NAME) : $(OBJ_PATH)
	@$(CC) -o $(NAME) $(OBJ_PSWAP) $(CFLAGS)


clean:
	@/bin/rm -rf $(OBJ_PATH)
	@echo "\033[31mObjects files \033[1;31m$(OBJS_LIST)\033[1;0m\033[31m removed.\033[0m"

fclean: clean
	@/bin/rm -rf $(NAME)
	@echo "\033[31mBin \033[1;31m$(NAME)\033[1;0m\033[31m removed.\033[0m"

re: fclean all


.PHONY: all re clean fclean libs


