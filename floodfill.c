/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkhbiri <alkhbiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:29:15 by alkhbiri          #+#    #+#             */
/*   Updated: 2025/03/05 16:58:22 by alkhbiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**floodfill(char **lines, int x, int y)
{
	if (!lines[y] || lines[y][x] == 'S' || lines[y][x] == '1')
		return (lines);
	lines[y][x] = 'S';
	lines = floodfill(lines, x + 1, y);
	lines = floodfill(lines, x - 1, y);
	lines = floodfill(lines, x, y + 1);
	lines = floodfill(lines, x, y - 1);
	return (lines);
}

char	*maps_s(char *line)
{
	int		map;
	char	*maps;

	map = open(line, O_RDWR, 0777);
	maps = NULL;
	while (1)
	{
		line = get_next_line(map);
		if (!line)
			break ;
		maps = ft_strjoin(maps, line);
		free(line);
	}
	// while (1);
	close(map);
	return (maps);
}

void	flood_test(char **lines)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (lines[i])
	{
		j = 0;
		while (lines[i][j])
		{
			if (lines[i][j] == 'E' || lines[i][j] == 'C')
				write_err("non accessable path to items or exit");
			j++;
		}
		i++;
	}
}

t_pos	player_pos(char **lines, int k)
{
	int		i;
	int		j;
	t_pos	pp;

	i = 0;
	j = 0;
	while (lines[i])
	{	
		j = 0;
		while (lines[i][j])
		{
			if (lines[i][j] == 'P')
			{
				k = 1;
				break ;
			}
			j++;
		}
		if (k == 1)
			break ;
		i++;
	}
	pp.x = i;
	pp.y = j;
	return (pp);
}
