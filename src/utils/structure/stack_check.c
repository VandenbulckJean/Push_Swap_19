/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 11:19:46 by jvanden-          #+#    #+#             */
/*   Updated: 2021/08/10 11:42:05 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

int	stack_double_nbr_check(t_stack *stack)
{
	t_list	*base;
	t_list	*test_buffer;

	base = stack->first;
	while (base)
	{
		test_buffer = base->next;
		while (test_buffer)
		{
			if (test_buffer->nbr == base->nbr)
				return (0);
			test_buffer = test_buffer->next;
		}
		base = base->next;
	}
	return (1);
}

int	stacks_sorted_check(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*buffer;

	if (!stack_a->first)
		return (0);
	buffer = stack_a->first;
	while (buffer->next)
	{
		if (buffer->nbr > buffer->next->nbr)
			return (0);
		buffer = buffer->next;
	}
	if (stack_b->first != NULL)
		return (0);
	return (1);
}
