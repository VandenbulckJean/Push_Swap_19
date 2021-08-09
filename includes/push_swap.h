/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 12:00:51 by jvanden-          #+#    #+#             */
/*   Updated: 2021/08/09 18:01:56 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

//Structures

typedef struct s_list
{
	int				nbr;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	t_list	*first;
	int		count;
	int		max;
	int		min;
}	t_stack;

typedef struct s_data
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**argv;
	int		is_argv_malloc;
}	t_data;

//prototypes

//utils
char			**ft_strsplit(char const *s, char c);
int				ft_strcmp(const char *s1, const char *s2);
int				count_element_char_array(char **array);
int				ft_isdigit(int c);
size_t			ft_strlen(const char *s);

//parsing
int				clean_argv(int *argc, char ***argv, t_data *data);
int				check_argv(int argc, char **argv);

#endif