/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkhbiri <alkhbiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:28:48 by alkhbiri          #+#    #+#             */
/*   Updated: 2025/03/01 14:18:25 by alkhbiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	wall_draw(char **lines, t_data *img)
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
				mlx_put_image_to_window((img)->mlx_ptr,
					(img)->win, (img)->img_wall, j * 60, i * 60);
			j++;
		}
		i++;
	}
}

void	coin(char **lines, t_data *img)
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
				mlx_put_image_to_window((img)->mlx_ptr,
					(img)->win, (img)->img_coin, j * 60, i * 60);
			j++;
		}
		i++;
	}
}

void	door_draw(char **lines, t_data *img)
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
				mlx_put_image_to_window((img)->mlx_ptr,
					(img)->win, img->img_door, j * 60, i * 60);
				break ;
			}
			j++;
		}
		i++;
	}
}

void	player_draw(char **lines, t_data *img)
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
			if (lines[i][j] == 'P')
			{
				mlx_put_image_to_window((img)->mlx_ptr,
					(img)->win, (img)->img_pface, j * 60, i * 60);
				break ;
			}
			j++;
		}
		i++;
	}
}

void	drawing(char *maps)
{
	t_data	img;
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	img.lines = ft_split(maps, '\n');
	img.count = 1;
	img = putimage(&img, mlx_ptr);
	floor_drawing(img.lines, &img);
	wall_draw(img.lines, &img);
	door_draw(img.lines, &img);
	player_draw(img.lines, &img);
	coin(img.lines, &img);
	mlx_hook(img.win, 2, 1, move_player, &img);
	mlx_loop(img.mlx_ptr);
}
