/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkhbiri <alkhbiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:28:41 by alkhbiri          #+#    #+#             */
/*   Updated: 2025/02/27 10:10:33 by alkhbiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "so_long.h"

static void	wall_draw_bonus(char **lines, t_data *img)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (lines[i])
	{
		j = 0;
		while (lines[i][j])
		{
			if (lines[i][j] == '1')
				mlx_put_image_to_window(img->mlx_ptr,
					img->win, img->img_wall, j * 60, i * 60);
			j++;
		}
		i++;
	}
}

static void	collectable_draw_bonus(char **lines, t_data *img)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (lines[i])
	{
		j = 0;
		while (lines[i][j])
		{
			if (lines[i][j] == 'C')
				mlx_put_image_to_window(img->mlx_ptr,
					img->win, img->img_collectable, j * 60, i * 60);
			j++;
		}
		i++;
	}
}

static void	monster_draw_bonus(char **lines, t_data *img)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (lines[i])
	{
		j = 0;
		while (lines[i][j])
		{
			if (lines[i][j] == 'M')
				mlx_put_image_to_window(img->mlx_ptr,
					img->win, img->monster, j * 60, i * 60);
			j++;
		}
		i++;
	}
}

static void	door_draw_bonus(char **lines, t_data *img)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (lines[i])
	{
		j = 0;
		while (lines[i][j])
		{
			if (lines[i][j] == 'E')
			{
				mlx_put_image_to_window(img->mlx_ptr,
					img->win, img->img_door, j * 60, i * 60);
				break ;
			}
			j++;
		}
		i++;
	}
}

void	drawing_bonus(char *maps)
{
	t_data	img;
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	img.lines = ft_split(maps, '\n');
	img.count = 1;
	img = putimage_bonus(&img, mlx_ptr);
	floor_drawing_bonus(img.lines, &img);
	wall_draw_bonus(img.lines, &img);
	door_draw_bonus(img.lines, &img);
	player_draw_bonus(img.lines, &img);
	collectable_draw_bonus(img.lines, &img);
	monster_draw_bonus(img.lines, &img);
	mlx_hook(img.win, 2, 1, move_player_bonus, &img);
	mlx_loop_hook(img.mlx_ptr, monster_move, &img);
	mlx_loop(img.mlx_ptr);
}
