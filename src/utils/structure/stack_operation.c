/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 13:08:44 by jvanden-          #+#    #+#             */
/*   Updated: 2021/08/10 13:42:02 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	swap(t_stack *stack)
{
	int	buffer;

	if (stack->count <= 1)
		return ;
	else
	{
		buffer = stack->first->next->nbr;
		stack->first->next->nbr = stack->first->nbr;
		stack->first->nbr = buffer;
	}
}

int	push(t_stack *receiver, t_stack *giver)
{
	if (giver->count == 0)
		return (1);
	if (!stack_add_nbr(receiver, stack_remove_n_return_first_nbr(giver)))
		return (0);
	return (1);
}

void	rotate(t_stack *stack)
{
	t_list	*last;
	t_list	*buffer;

	if (stack->count <= 1)
		return ;
	buffer = stack->first;
	stack->first = stack->first->next;
	buffer->next = NULL;
	last = stack->first;
	while (last->next)
		last = last->next;
	last->next = buffer;
}

void	reverse_rotate(t_stack *stack)
{
	t_list	*second_to_last;
	t_list	*buffer;

	if (stack->count <= 1)
		return ;
	second_to_last = stack->first;
	while (second_to_last->next->next)
		second_to_last = second_to_last->next;
	buffer = second_to_last->next;
	second_to_last->next = NULL;
	buffer->next = stack->first;
	stack->first = buffer;
}
