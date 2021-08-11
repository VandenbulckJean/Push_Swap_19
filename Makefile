# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/09 12:28:29 by jvanden-          #+#    #+#              #
#    Updated: 2021/08/11 09:45:01 by jvanden-         ###   ########.fr        #
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
				algorithm.c 
				
SRCS_UTILS	=	algorithm_functions/count_rotation_to_sorted.c \
				algorithm_functions/find_best_insertion.c \
				algorithm_functions/stack_store_top_three_max.c \
				functions/count_element_char_array.c \
				functions/ft_atoi.c \
				functions/ft_isdigit.c \
				functions/ft_max.c \
				functions/ft_min.c \
				functions/ft_putchar.c \
				functions/ft_putnbr.c \
				functions/ft_strcmp.c \
				functions/ft_strlen.c \
				functions/ft_strsplit.c \
				functions/ft_putstr.c \
				structure/insertion_operation.c \
				structure/insertion.c \
				structure/list.c \
				structure/stack_check.c \
				structure/stack_do_n_print_operation.c \
				structure/stack_management.c \
				structure/stack_operation.c 

SRCS_PSWAP2	=	$(addprefix $(SRCS_PATH), $(SRCS_PSWAP)) \
				$(addprefix $(SRCS_PATH)utils/, $(SRCS_UTILS))

OBJ_PSWAP	=	$(SRCS_PSWAP2:.c=.o)

######### RULES #######

all : $(NAME)

$(NAME) : $(OBJ_PSWAP)
	@$(CC) -o $(NAME) $(OBJ_PSWAP) $(CFLAGS)


clean:
	@/bin/rm -rf $(OBJ_PSWAP)

fclean: clean
	@/bin/rm -rf $(NAME)

re: fclean all

.PHONY: all re clean fclean 


