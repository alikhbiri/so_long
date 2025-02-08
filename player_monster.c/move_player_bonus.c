/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkhbiri <alkhbiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:01:04 by alkhbiri          #+#    #+#             */
/*   Updated: 2025/02/08 18:04:32 by alkhbiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

static void	move_up(t_data *img)
{
	char	**lines;
	t_pos	pp;

	lines = img->lines;
	pp = player_pos_bonus(lines, 0);
	if (lines[(pp.x) - 1][pp.y] != '1' && lines[(pp.x) - 1][pp.y] != 'Q')
	{
		cp_bonus(img);
		if (lines[(pp.x) - 1][pp.y] == 'M')
			return (write(1, "haha loser", 10), exit (1));
		if (lines[(pp.x) - 1][pp.y] == 'X')
			return (write(1, "you win", 7), exit (0));
		if (!fined_exit(lines))
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
	pp = player_pos_bonus(lines, 0);
	if (lines[(pp.x) + 1][pp.y] != '1' && lines[(pp.x) + 1][pp.y] != 'Q')
	{
		cp_bonus(img);
		if (lines[(pp.x) + 1][pp.y] == 'M')
			return (write(1, "haha loser", 10), exit (1));
		if (lines[(pp.x) + 1][pp.y] == 'X')
			return (write(1, "you win", 7), exit (0));
		if (!fined_exit(lines))
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
	pp = player_pos_bonus(lines, 0);
	if (lines[pp.x][pp.y + 1] != '1' && lines[pp.x][pp.y + 1] != 'Q')
	{
		cp_bonus(img);
		if (lines[pp.x][pp.y + 1] == 'M')
			return (write(1, "haha loser", 10), exit (1));
		if (lines[pp.x][pp.y + 1] == 'X')
			return (write(1, "you win", 7), exit (0));
		if (!fined_exit(lines))
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
	pp = player_pos_bonus(lines, 0);
	if (lines[pp.x][pp.y - 1] != '1' && lines[pp.x][pp.y - 1] != 'Q')
	{
		cp_bonus(img);
		if (lines[pp.x][pp.y - 1] == 'M')
			return (write(1, "haha loser", 10), exit (1));
		if (lines[pp.x][pp.y - 1] == 'X')
			return (write(1, "you win", 7), exit (0));
		if (!fined_exit(lines))
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

int	move_player_bonus(int key, void *p)
{
	t_data	*map;
	char	**lines;
	int		i;

	map = p;
	lines = map->lines;
	if (key == 126)
		move_up(p);
	else if (key == 125)
		move_down(p);
	else if (key == 124)
		move_right(p);
	else if (key == 123)
		move_left(p);
	else if (key == 53)
		exit (1);
	i = collectable_checker(lines);
	if (i == 0)
		open_door(lines, map);
	return (0);
}