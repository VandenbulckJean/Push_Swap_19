/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 09:45:54 by jvanden-          #+#    #+#             */
/*   Updated: 2021/08/10 10:42:47 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

t_list	*ft_lstnew(int nbr, t_list *next)
{
	t_list	*new_el;

	new_el = (t_list *)malloc(sizeof(t_list));
	if (!new_el)
		return (NULL);
	new_el->nbr = nbr;
	new_el->next = next;
	return (new_el);
}

void	ft_lstclear(t_list *lst)
{
	t_list	*buffer;
	t_list	*to_delete;

	buffer = lst;
	while (buffer)
	{
		to_delete = buffer;
		buffer = buffer->next;
		free(to_delete);
	}
	lst = NULL;
}
