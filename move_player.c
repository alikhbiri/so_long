/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkhbiri <alkhbiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:30:22 by alkhbiri          #+#    #+#             */
/*   Updated: 2025/03/01 14:29:35 by alkhbiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_up(t_data *img)
{
	char	**lines;
	t_pos	pp;

	lines = img->lines;
	pp = player_pos(lines, 0);
	if (lines[(pp.x) - 1][pp.y] != '1')
	{
		ft_putnbr (img->count++);
		write (1, "\n", 1);
		if (lines[(pp.x) - 1][pp.y] == 'X')
			return (write(1, "Winner", 9), exit (0));
		if (!find_exit(lines))
			lines[pp.x][pp.y] = 'E';
		else
			lines[pp.x][pp.y] = '0';
		lines[(pp.x) - 1][pp.y] = 'P';
		mlx_put_image_to_window(img->mlx_ptr,
			img->win, img->img_floor, pp.y * 60, pp.x * 60);
		if (lines[(pp.x)][pp.y] == 'E')
			mlx_put_image_to_window(img->mlx_ptr,
				img->win, img->img_door, pp.y * 60, pp.x * 60);
		mlx_put_image_to_window(img->mlx_ptr,
			img->win, img->img_pback, pp.y * 60, (pp.x - 1) * 60);
	}
}

static void	move_down(t_data *img)
{
	char	**lines;
	t_pos	pp;

	lines = img->lines;
	pp = player_pos(lines, 0);
	if (lines[(pp.x) + 1][pp.y] != '1')
	{
		ft_putnbr (img->count++);
		write (1, "\n", 1);
		if (lines[(pp.x) + 1][pp.y] == 'X')
			return (write(1, "Winner", 9), exit (0));
		if (!find_exit(lines))
			lines[pp.x][pp.y] = 'E';
		else
			lines[pp.x][pp.y] = '0';
		lines[(pp.x) + 1][pp.y] = 'P';
		mlx_put_image_to_window(img->mlx_ptr,
			img->win, img->img_floor, pp.y * 60, pp.x * 60);
		if (lines[(pp.x)][pp.y] == 'E')
			mlx_put_image_to_window(img->mlx_ptr,
				img->win, img->img_door, pp.y * 60, pp.x * 60);
		mlx_put_image_to_window(img->mlx_ptr,
			img->win, img->img_pface, pp.y * 60, (pp.x + 1) * 60);
	}
}

static void	move_right(t_data *img)
{
	char	**lines;
	t_pos	pp;

	lines = img->lines;
	pp = player_pos(lines, 0);
	if (lines[pp.x][pp.y + 1] != '1')
	{
		ft_putnbr (img->count++);
		write (1, "\n", 1);
		if (lines[pp.x][pp.y + 1] == 'X')
			return (write(1, "Winner", 9), exit (0));
		if (!find_exit(lines))
			lines[pp.x][pp.y] = 'E';
		else
			lines[pp.x][pp.y] = '0';
		lines[pp.x][(pp.y) + 1] = 'P';
		mlx_put_image_to_window(img->mlx_ptr,
			img->win, img->img_floor, pp.y * 60, pp.x * 60);
		if (lines[pp.x][pp.y] == 'E')
			mlx_put_image_to_window(img->mlx_ptr,
				img->win, img->img_door, pp.y * 60, pp.x * 60);
		mlx_put_image_to_window(img->mlx_ptr,
			img->win, img->img_pright, (pp.y + 1) * 60, pp.x * 60);
	}
}

static void	move_left(t_data *img)
{
	char	**lines;
	t_pos	pp;

	lines = img->lines;
	pp = player_pos(lines, 0);
	if (lines[pp.x][pp.y - 1] != '1')
	{
		ft_putnbr (img->count++);
		write (1, "\n", 1);
		if (lines[pp.x][pp.y - 1] == 'X')
			return (write(1, "Winner", 9), exit (0));
		if (!find_exit(lines))
			lines[pp.x][pp.y] = 'E';
		else
			lines[pp.x][pp.y] = '0';
		mlx_put_image_to_window(img->mlx_ptr,
			img->win, img->img_floor, pp.y * 60, pp.x * 60);
		if (lines[pp.x][pp.y] == 'E')
			mlx_put_image_to_window(img->mlx_ptr,
				img->win, img->img_door, pp.y * 60, pp.x * 60);
		mlx_put_image_to_window(img->mlx_ptr,
			img->win, img->img_pleft, (pp.y - 1) * 60, pp.x * 60);
		lines[pp.x][(pp.y) - 1] = 'P';
	}
}

int	move_player(int key, void *p)
{
	t_data	*map;
	char	**lines;
	int		i;

	map = p;
	lines = map->lines;
	if (key == 65307)
		exit(1);
	else if (key == 119 || key == 65362)
		move_up(p);
	else if (key == 115 || key == 65364)
		move_down(p);
	else if (key == 100 || key == 65363)
		move_right(p);
	else if (key == 97 || key == 65361)
		move_left(p);
	i = coin_checker(lines);
	if (i == 0)
		open_door(lines, map);
	return (0);
}
