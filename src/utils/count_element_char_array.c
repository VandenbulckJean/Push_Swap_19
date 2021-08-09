/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_element_char_array.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 14:15:55 by jvanden-          #+#    #+#             */
/*   Updated: 2021/08/09 14:17:59 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	count_element_char_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}
