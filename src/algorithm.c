/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 12:53:03 by jvanden-          #+#    #+#             */
/*   Updated: 2021/08/10 18:09:43 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	stack_sort_two(t_stack *stack, char stack_id)
{
	if (stack->first->nbr > stack->first->next->nbr)
		do_n_print_swap(stack, stack_id);
}

void	stack_sort_three(t_stack *stack, char stack_id)
{
	int	first;
	int	second;
	int	third;

	first = stack->first->nbr;
	second = stack->first->next->nbr;
	third = stack->first->next->next->nbr;
	if (first > second && second > third && first > third)
	{
		do_n_print_swap(stack, stack_id);
		do_n_print_reverse_rotation(stack, stack_id);
	}
	else if (first < second && second > third && first < third)
	{
		do_n_print_reverse_rotation(stack, stack_id);
		do_n_print_swap(stack, stack_id);
	}
	else if (first > second && second < third && first < third)
		do_n_print_swap(stack, stack_id);
	else if (first < second && second > third && first > third)
		do_n_print_reverse_rotation(stack, stack_id);
	else if (first > second && second < third && first > third)
		do_n_print_rotation(stack, stack_id);
}

void	insertion_sorting_algorithm(t_stack *stack_a, t_stack *stack_b)
{
	t_insertion	insertion;
	int			nbr;

	while (stack_a->count > 3)
	{
		insertion = find_best_insertion(stack_a, stack_b);
		//do_op(insertion, stack_a, stack_b);
		if (!push(stack_b, stack_a))
			return ;
		write(1, "pb\n", 3);
	}
	nbr = count_rotation_to_sorted(stack_b);
	if (nbr < (stack_b->count - nbr) % stack_b->count)
		while (stack_b->first->nbr != stack_b->max)
			do_n_print_rotation(stack_b, 'b');
	else
		while (stack_b->first->nbr != stack_b->max)
			do_n_print_reverse_rotation(stack_b, 'b');

	stack_sort_three(stack_a, 'a');
	while (stack_b->first)
	{
		if (!push(stack_a, stack_b))
			return ;
		write(1, "pa\n", 3);
	}
}
