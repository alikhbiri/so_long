/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkhbiri <alkhbiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:29:47 by alkhbiri          #+#    #+#             */
/*   Updated: 2025/03/01 14:12:26 by alkhbiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**arg_m(char const *s, char c)
{
	char	**sp;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
			j++;
		while (s[i] && s[i] != c)
			i++;
		if (s[i])
			i++;
	}
	sp = (char **)malloc(sizeof(char *) * (j + 1));
	if (!sp)
		return (NULL);
	return (sp);
}

static char	**freedem(char **sp, int k)
{
	int	i;

	i = 0;
	while (i < k)
	{
		free(sp[i]);
		i++;
	}
	free(sp);
	return (NULL);
}

static char	**splloc(char const *s, char c, char **sp)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i] && s[i] != c)
		{
			j++;
			i++;
		}
		if (j != 0)
		{
			sp[k] = (char *)malloc(sizeof(char) * (j + 1));
			if (!sp[k])
				return (freedem(sp, k));
			k++;
		}
		if (s[i])
			i++;
	}
	return (sp);
}

static char	**printsp(char const *s, char c, char **sp)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		j = 0;
		if (s[i] && s[i] != c)
		{
			while (s[i] && s[i] != c)
			{
				sp[k][j] = s[i];
				j++;
				i++;
			}
			sp[k][j] = '\0';
			k++;
		}
		if (s[i])
			i++;
	}
	sp[k] = 0;
	return (sp);
}

char	**ft_split(char const *s, char c)
{
	char	**sp;

	if (!s)
		return (NULL);
	sp = arg_m(s, c);
	if (sp != NULL)
	{
		sp = splloc(s, c, sp);
		if (sp == NULL)
		{
			return (NULL);
		}
		sp = printsp(s, c, sp);
		return (sp);
	}
	return (sp);
}
