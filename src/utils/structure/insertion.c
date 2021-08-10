/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 14:24:05 by jvanden-          #+#    #+#             */
/*   Updated: 2021/08/10 17:23:34 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

static int	amount_rotation_giver(t_list *stack_element, t_stack *giving_stack)
{
	int		answer;
	t_list	*buffer;

	answer = 0;
	buffer = giving_stack->first;
	while (buffer != stack_element)
	{
		buffer = buffer->next;
		answer++;
	}
	return (answer);
}

static int	amount_ratotation_receiver_two(t_list *stack_element,
t_list *list_buffer)
{
	int		nbr_buffer;
	int		answer;
	int		answer_buffer;

	answer = 0;
	answer_buffer = 0;
	nbr_buffer = -2147483648;
	while (list_buffer)
	{
		if (list_buffer->nbr < stack_element->nbr
			&& list_buffer->nbr > nbr_buffer)
		{
			nbr_buffer = list_buffer->nbr;
			answer = answer_buffer;
		}
		answer_buffer++;
		list_buffer = list_buffer->next;
	}
}

static int	amount_rotation_receiver(t_list *stack_element,
t_stack *receiving_stack)
{
	t_list	*list_buffer;
	int		answer;

	answer = 0;
	if (receiving_stack->count < 2)
		return (0);
	list_buffer = receiving_stack->first;
	if (stack_element->nbr < receiving_stack->min)
	{
		while (list_buffer->nbr != receiving_stack->max)
		{
			answer++;
			list_buffer = list_buffer->next;
		}
	}
	else
		answer = amount_ratotation_receiver_two(stack_element, list_buffer);
	return (answer);
}

static int	amount_operation(t_insertion *insertion)
{
	int		rarrb;
	int		rr;
	int		rrr;

	rarrb = ft_min(insertion->ra, insertion->rra)
		+ ft_min(insertion->rb, insertion->rrb);
	rr = ft_max(insertion->ra, insertion->rb);
	rrr = ft_max(insertion->rra, insertion->rrb);
	insertion->amount_operation = ft_min(rarrb, rrr);
	insertion->amount_operation = ft_min(insertion->amount_operation, rr);
	if (insertion->amount_operation == rarrb)
		insertion->operation = '0';
	else if (insertion->amount_operation == rr)
		insertion->operation = '1';
	else
		insertion->operation = '2';
}

void	insertion_fill(t_insertion *to_fill, t_list *stack_element,
t_stack *stack_a, t_stack *stack_b)
{
	to_fill->ra = amount_rotation_giver(stack_element, stack_a);
	to_fill->rra = (stack_a->count - to_fill->ra) % stack_a->count;
	to_fill->rb = amount_rotation_receiver(stack_element, stack_b);
	if (stack_b->count != 0)
		to_fill->rrb = (stack_b->count - to_fill->rb) % stack_b->count;
	else
		to_fill->rrb = 0;
	amount_operation(to_fill);
}
