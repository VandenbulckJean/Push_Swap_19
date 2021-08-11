/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 12:00:51 by jvanden-          #+#    #+#             */
/*   Updated: 2021/08/11 11:44:14 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				nbr;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	t_list	*first;
	int		count;
	int		max;
	int		max_2;
	int		max_3;
	int		min;
}	t_stack;

typedef struct s_insertion
{
	int		ra;
	int		rb;
	int		rra;
	int		rrb;
	int		amount_operation;
	char	operation;
	int		nbr;
}	t_insertion;

typedef struct s_data
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**argv;
	int		is_argv_malloc;
}	t_data;

//prototypes
	//utils
		//functions
char			**ft_strsplit(char const *s, char c);
int				ft_strcmp(const char *s1, const char *s2);
int				count_element_char_array(char **array);
int				ft_isdigit(int c);
size_t			ft_strlen(const char *s);
int				ft_atoi(const char *str);
void			ft_putstr(char const *str);
void			ft_putnbr(int n);
void			ft_putchar(char c);
int				ft_min(int a, int b);
int				ft_max(int a, int b);
		//structure
			//list
t_list			*ft_lstnew(int nbr, t_list *next);
void			ft_lstclear(t_list *lst);
			//stack
t_stack			*stack_init(void);
t_stack			*stack_init_n_fill_from_char_array(int count, char **array);
void			stack_print(t_stack *stack);
int				stack_add_nbr(t_stack *stack, int nbr);
int				stack_remove_n_return_first_nbr(t_stack *stack);
int				stack_double_nbr_check(t_stack *stack);
int				stacks_sorted_check(t_stack *stack_a, t_stack *stack_b);
void			swap(t_stack *stack);
int				push(t_stack *receiver, t_stack *giver);
void			rotate(t_stack *stack);
void			reverse_rotate(t_stack *stack);
void			do_n_print_rotation(t_stack *stack, char stack_id);
void			do_n_print_reverse_rotation(t_stack *stack, char stack_id);
void			do_n_print_swap(t_stack *stack, char stack_id);
			//insertion
void			insertion_fill(t_insertion *to_fill, t_list *stack_element,
					t_stack *stack_a, t_stack *stack_b);
void			do_insertion_operation(t_insertion insertion,
					t_stack *stack_a, t_stack *stack_b);
		//algorithm functions
void			stack_store_top_three_max(t_stack *stack);
t_insertion		find_best_insertion(t_stack *stack_a, t_stack *stack_b);
int				count_rotation_to_sorted(t_stack *stack);
	//parsing
int				clean_argv(int *argc, char ***argv, t_data *data);
int				check_argv(int argc, char **argv);
	//algorithm
void			stack_sort_two(t_stack *stack, char stack_id);
void			stack_sort_three(t_stack *stack, char stack_id);
void			insertion_sorting_algorithm(t_stack *stack_a, t_stack *stack_b);
	//exit
void			free_n_exit(t_data *data, int level);
void			free_stack(t_stack *stack);

#endif