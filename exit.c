/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkhbiri <alkhbiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:29:06 by alkhbiri          #+#    #+#             */
/*   Updated: 2025/03/05 17:03:42 by alkhbiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_exit(char **lines)
{
	int	i;
	int	j;
	int	check;

	i = 0;
	j = 0;
	check = 0;
	while (lines[i])
	{
		j = 0;
		while (lines[i][j])
		{
			if (lines[i][j] == 'E' || lines[i][j] == 'X')
			{
				check = 1;
				break ;
			}
			j++;
		}
		i++;
	}
	return (check);
}

int	coin_checker(char **lines)
{
	int	i;
	int	j;
	int	check;

	i = 0;
	j = 0;
	check = 0;
	while (lines[i])
	{
		j = 0;
		while (lines[i][j])
		{
			if (lines[i][j] == 'C')
				check++;
			j++;
		}
		i++;
	}
	return (check);
}

void	open_door(char **lines, t_data *map)
{
	int	i;
	int	j;

	i = 0;
	while (lines[i])
	{
		j = 0;
		while (lines[i][j])
		{
			if (lines[i][j] == 'E')
			{
				lines[i][j] = 'X';
				mlx_put_image_to_window(map->mlx_ptr,
					map->win, map->img_floor, j * 60, i * 60);
				if (lines[i][j + 1] == '0')
					mlx_put_image_to_window(map->mlx_ptr,
						map->win, map->img_floor, (j + 1) * 60, i * 60);
				mlx_put_image_to_window(map->mlx_ptr,
					map->win, map->img_opendoor, j * 60, i * 60);
				break ;
			}
			j++;
		}
		i++;
	}
}
#include "so_long.h"

int	close_game(t_game *game)
{
	free_resources(game);
	exit(0);
}

void	error_exit(t_game *game, char *message)
{
	ft_putendl_fd(message, 2);
	free_resources(game);
	exit(1);
}
