/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_insertion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 14:20:32 by jvanden-          #+#    #+#             */
/*   Updated: 2021/08/11 10:18:59 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

t_insertion	find_best_insertion(t_stack *stack_a, t_stack *stack_b)
{
	t_list		*list_buffer;
	t_insertion	best;
	t_insertion	insertion_buffer;

	list_buffer = stack_a->first;
	while (list_buffer->nbr == stack_a->max
		|| list_buffer->nbr == stack_a->max_2
		|| list_buffer->nbr == stack_a->max_3)
		list_buffer = list_buffer->next;
	insertion_fill(&best, list_buffer, stack_a, stack_b);
	list_buffer = list_buffer->next;
	while (list_buffer)
	{
		insertion_fill(&insertion_buffer, list_buffer, stack_a, stack_b);
		if (insertion_buffer.amount_operation < best.amount_operation
			&& list_buffer->nbr != stack_a->max
			&& list_buffer->nbr != stack_a->max_2
			&& list_buffer->nbr != stack_a->max_3)
			best = insertion_buffer;
		list_buffer = list_buffer->next;
	}
	return (best);
}
