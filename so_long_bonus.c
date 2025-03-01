/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkhbiri <alkhbiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:30:36 by alkhbiri          #+#    #+#             */
/*   Updated: 2025/03/01 14:28:19 by alkhbiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	write_err_bonus(char *str)
{
	write(2, "Error\n", 6);
	ft_putstr_fd(str, 2);
	exit (1);
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
		name_error_bonus(line);
		maps = maps_s_bonus(line);
		if (!maps)
			write_err_bonus("empty or non existing file");
		lines = ft_split(maps, '\n');
		parssing_bonus(lines, maps);
		pp = player_pos_bonus(lines, 0);
		lines = floodfill_bonus(lines, pp.y, pp.x);
		flood_test_bonus(lines);
		drawing_bonus(maps);
	}
}
