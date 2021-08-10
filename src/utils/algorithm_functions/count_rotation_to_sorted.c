/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_rotation_to_sorted.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 18:07:24 by jvanden-          #+#    #+#             */
/*   Updated: 2021/08/10 18:09:01 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

int	count_rotation_to_sorted(t_stack *stack)
{
	t_list	*buffer;
	int		answer;

	buffer = stack->first;
	answer = 0;
	while (buffer->nbr != stack->max)
	{
		buffer = buffer->next;
		answer++;
	}
	return (answer);
}
