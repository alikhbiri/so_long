/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkhbiri <alkhbiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:30:02 by alkhbiri          #+#    #+#             */
/*   Updated: 2025/02/19 14:30:03 by alkhbiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "so_long.h"

int	map_len(char **lines)
{
	int	ls;

	ls = 0;
	while (*lines)
	{
		ls++;
		lines++;
	}
	return (ls);
}

int	line_len(char *lines)
{
	int	ls;

	ls = 0;
	while (lines[ls])
		ls++;
	return (ls);
}

void	len_check(char **lines)
{
	int	i;
	int	ls;
	int	l;

	i = 0;
	ls = line_len(lines[i]);
	while (lines[i])
	{
		l = line_len(lines[i]);
		if (l != ls)
		{
			write(2, "Error\n", 6);
			ft_putstr_fd("map is not rectangle", 2);
			exit (1);
		}
		i++;
	}
}
