/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 12:02:26 by jvanden-          #+#    #+#             */
/*   Updated: 2021/08/09 18:02:40 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_data	data;

	data.is_argv_malloc = 0;
	if (argc == 0)
		return (EXIT_SUCCESS);
	if (!(clean_argv(&argc, &argv, &data)))
		free_n_exit(&data, 0);
	if (!(check_argv))
		free_n_exit(&data, 0);
}
