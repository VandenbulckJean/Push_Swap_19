/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_store_top_three_max.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 12:56:06 by jvanden-          #+#    #+#             */
/*   Updated: 2021/08/11 09:49:37 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	stack_store_top_three_max(t_stack *stack)
{
	t_list	*buffer;

	stack->max_2 = -2147483648;
	stack->max_3 = -2147483648;
	buffer = stack->first;
	while (buffer)
	{
		if (buffer->nbr > stack->max_2 && buffer->nbr != stack->max)
			stack->max_2 = buffer->nbr;
		buffer = buffer->next;
	}
	buffer = stack->first;
	while (buffer)
	{
		if (buffer->nbr > stack->max_3 && buffer->nbr
			!= stack->max && buffer->nbr != stack->max_2)
			stack->max_3 = buffer->nbr;
		buffer = buffer->next;
	}
}
