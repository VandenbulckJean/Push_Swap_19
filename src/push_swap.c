/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 12:02:26 by jvanden-          #+#    #+#             */
/*   Updated: 2021/08/11 14:14:13 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sorting_algorithm(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->count == 1)
		return ;
	else if (stack_a->count == 2)
		stack_sort_two(stack_a, 'a');
	else if (stack_a->count == 3)
		stack_sort_three(stack_a, 'a');
	else
	{
		stack_store_top_three_max(stack_a);
		insertion_sorting_algorithm(stack_a, stack_b);
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	data.is_argv_malloc = 0;
	if (argc == 1)
		return (EXIT_SUCCESS);
	if (!(clean_argv(&argc, &argv, &data)))
		free_n_exit(&data, 0);
	if (!(check_argv(argc, argv)))
		free_n_exit(&data, 0);
	data.stack_a = stack_init_n_fill_from_char_array(argc, argv);
	if (!data.stack_a)
		free_n_exit(&data, 0);
	data.stack_b = stack_init();
	if (!data.stack_b)
		free_n_exit(&data, 1);
	if (!stack_double_nbr_check(data.stack_a))
		free_n_exit(&data, 2);
	if (stacks_sorted_check(data.stack_a, data.stack_b))
		free_n_exit(&data, 3);
	sorting_algorithm(data.stack_a, data.stack_b);
	free_n_exit(&data, 3);
}
