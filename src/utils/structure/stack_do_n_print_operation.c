/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_do_n_print_operation.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 13:47:03 by jvanden-          #+#    #+#             */
/*   Updated: 2021/08/10 17:54:13 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	do_n_print_rotation(t_stack *stack, char stack_id)
{
	rotate(stack);
	write(1, "r", 1);
	write(1, &stack_id, 1);
	write(1, "\n", 1);
}

void	do_n_print_reverse_rotation(t_stack *stack, char stack_id)
{
	reverse_rotate(stack);
	write(1, "rr", 2);
	write(1, &stack_id, 1);
	write(1, "\n", 1);
}

void	do_n_print_swap(t_stack *stack, char stack_id)
{
	swap(stack);
	write(1, "s", 1);
	write(1, &stack_id, 1);
	write(1, "\n", 1);
}
