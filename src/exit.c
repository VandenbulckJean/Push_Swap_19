/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_n_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 14:45:26 by jvanden-          #+#    #+#             */
/*   Updated: 2021/08/09 14:57:48 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	free_argv(char **argv)
{
	int	i;

	i = -1;
	while (argv[++i])
		free(argv[i]);
	free(argv);
}

static void	exit_error(void)
{
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	free_n_exit(t_data *data, int level)
{
	if (data->is_argv_malloc == 1)
		free_argv(data->argv);
	if (level <= 2)
		exit_error();
	if (level >= 2)
		exit(EXIT_SUCCESS);
}
