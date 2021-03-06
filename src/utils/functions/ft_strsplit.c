/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 14:01:01 by jvanden-          #+#    #+#             */
/*   Updated: 2021/08/10 10:52:48 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

static int	nb_word(char const *s, char c)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			res++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (res);
}

static int	s_wd(char const *s, char c, int i)
{
	int	res;

	res = 0;
	while (s[i] != c && s[i] != '\0')
	{
		res++;
		i++;
	}
	return (res);
}

static char	*next_word(char const *s, char c, int *i)
{
	char	*res;
	int		k;

	res = (char *)malloc(sizeof(char) * (s_wd(s, c, *i) + 1));
	if (!res)
		return (NULL);
	k = 0;
	while (s[*i] != c && s[*i])
		res[k++] = s[(*i)++];
	res[k] = '\0';
	return (res);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;

	if (s)
	{
		i = 0;
		res = (char **)malloc(sizeof(char *) * (nb_word(s, c) + 1));
		if (!res)
			return (NULL);
		j = 0;
		while (s[i] != '\0')
		{
			while (s[i] == c && s[i])
				i++;
			if (s[i])
				res[j++] = next_word(s, c, &i);
		}
		res[j] = 0;
		return (res);
	}
	else
		return (NULL);
}
