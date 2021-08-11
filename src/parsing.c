/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 14:27:27 by jvanden-          #+#    #+#             */
/*   Updated: 2021/08/11 14:14:55 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	clean_argv(int *argc, char ***argv, t_data *data)
{
	int	i;

	i = 0;
	if (*argc == 2)
	{
		*argv = ft_strsplit((*argv)[1], ' ');
		if (!(*argv))
			return (0);
		*argc = count_element_char_array(*argv);
		data->is_argv_malloc = 1;
		data->argv = *argv;
	}
	else
	{
		while (i < *argc - 1)
		{
			(*argv)[i] = (*argv)[i + 1];
			i++;
		}
		(*argv)[i] = 0;
		(*argc)--;
	}
	return (1);
}

static int	is_number_char(char *string)
{
	int	i;

	i = -1;
	if (!ft_strcmp(string, "-") || !ft_strcmp(string, "+"))
		return (0);
	if (string[0] == '-' || string[0] == '+')
		i++;
	while (string[++i])
		if (!ft_isdigit(string[i]))
			return (0);
	return (1);
}

static int	check_limits(char *string, char sign)
{
	if (sign == 'p' && ft_strcmp(string, "2147483647") > 0)
		return (0);
	else if (sign == '+' && ft_strcmp(string + 1, "2147483647") > 0)
		return (0);
	else if (sign == '-' && ft_strcmp(string + 1, "2147483648") > 0)
		return (0);
	else
		return (1);
}

static int	is_integer(char *string)
{
	int		len;
	char	sign;

	len = ft_strlen(string);
	sign = 'p';
	if (string[0] == '-')
	{
		sign = '-';
		len--;
	}
	if (string[0] == '+')
	{
		sign = '+';
		len--;
	}
	if (len > 10)
		return (0);
	else if (len < 10)
		return (1);
	else
		return (check_limits(string, sign));
}

int	check_argv(int argc, char **argv)
{
	int	i;

	i = -1;
	while (++i < argc)
	{
		if (!is_number_char(argv[i]))
			return (0);
		if (!is_integer(argv[i]))
			return (0);
	}
	return (1);
}
