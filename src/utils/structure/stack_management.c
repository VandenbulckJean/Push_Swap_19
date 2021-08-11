/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 09:50:29 by jvanden-          #+#    #+#             */
/*   Updated: 2021/08/11 09:38:49 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

int	stack_add_nbr(t_stack *stack, int nbr)
{
	t_list	*new_el;

	new_el = ft_lstnew(nbr, stack->first);
	if (!new_el)
	{
		free_stack(stack);
		return (0);
	}
	if (nbr > stack->max)
		stack->max = nbr;
	if (nbr < stack->min)
		stack->min = nbr;
	stack->first = new_el;
	stack->count++;
	return (1);
}

int	stack_remove_n_return_first_nbr(t_stack *stack)
{
	int		buffer;
	t_list	*to_delete;

	buffer = stack->first->nbr;
	to_delete = stack->first;
	stack->first = stack->first->next;
	free(to_delete);
	stack->count--;
	return (buffer);
}

t_stack	*stack_init(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->first = NULL;
	stack->count = 0;
	stack->min = 2147483647;
	stack->max = -2147483648;
	return (stack);
}

t_stack	*stack_init_n_fill_from_char_array(int count, char **array)
{
	t_stack	*stack;

	stack = stack_init();
	if (!stack)
		return (NULL);
	while (--count >= 0)
	{
		if (!stack_add_nbr(stack, ft_atoi(array[count])))
		{
			free_stack(stack);
			return (NULL);
		}
	}
	return (stack);
}

void	stack_print(t_stack *stack)
{
	t_list	*buffer;

	if (!stack)
		return ;
	buffer = stack->first;
	while (buffer)
	{
		ft_putnbr(buffer->nbr);
		ft_putchar('\n');
		buffer = buffer->next;
	}
	ft_putchar('\n');
}
