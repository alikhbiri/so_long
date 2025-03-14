/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkhbiri <alkhbiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:30:42 by alkhbiri          #+#    #+#             */
/*   Updated: 2025/03/05 17:00:01 by alkhbiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	write_err(char *str)
{
	write(2, "Error\n", 6);
	ft_putstr_fd(str, 2);
	exit (1);
}

void	ft_lik()
{
	system("leak so_long");
}

int	main(int ac, char **av)
{
	char	*line;
	char	*maps;
	char	**lines;
	t_pos	pp;

	if (ac == 2)
	{
		line = av[1];
		name_error(line);
		maps = maps_s(line);
		if (!maps)
			write_err("empty or non existing file");
		lines = ft_split(maps, '\n');
		// int i = 0;
		// while(lines[i])
		// 	free(lines[i++]);
		// free(lines);
		parssing(lines, maps);
		// exit(0);
		pp = player_pos(lines, 0);
		lines = floodfill(lines, pp.y, pp.x);
		flood_test(lines);
		drawing(maps);
	}
}
