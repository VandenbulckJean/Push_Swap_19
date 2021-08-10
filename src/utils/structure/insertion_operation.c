/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_operation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 18:10:26 by jvanden-          #+#    #+#             */
/*   Updated: 2021/08/10 18:16:38 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

static void	insertion_minimum(t_insertion insertion,
t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = -1;
	if (insertion.ra < insertion.rra)
		while (++i < insertion.ra)
			do_n_print_rotation(stack_a, 'a');
	else
		while (++i < insertion.rra)
			do_n_print_reverse_rotation(stack_a, 'a');
	i = -1;
	if (insertion.rb < insertion.rrb)
		while (++i < insertion.rb)
			do_n_print_rotation(stack_b, 'b');
	else
		while (++i < insertion.rrb)
			do_n_print_reverse_rotation(stack_b, 'a');
}

static void	insertion_rr(t_insertion insertion,
t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	while (i < ft_min(insertion.ra, insertion.rb))
	{
		rotate(stack_a);
		rotate(stack_b);
		write(1, "rr\n", 3);
		i++;
	}
	if (insertion.ra > insertion.rb)
		while (i++ < insertion.ra)
			do_print_ra(stack_a);
	else
		while (i++ < insertion.rb)
			do_print_rb(stack_b);
}

static void	insertion_rrr(t_insertion *insertion,
t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	while (i < ft_min(insertion->rra, insertion->rrb))
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
		write(1, "rrr\n", 4);
		i++;
	}
	if (insertion->rra > insertion->rrb)
		while (i++ < insertion->rra)
			do_print_rra(stack_a);
	else
	{
		while (i++ < insertion->rrb)
			do_print_rrb(stack_b);
	}
}

void	do_insertion_operation(t_insertion insertion,
t_stack *stack_a, t_stack *stack_b)
{
	if (insertion.operation == '1')
		insertion_rr(insertion, stack_a, stack_b);
	else if (insertion.operation == '2')
		insertion_rrr(&insertion, stack_a, stack_b);
	else
		insertion_minimum(insertion, stack_a, stack_b);
}
