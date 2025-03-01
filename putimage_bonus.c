/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putimage_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkhbiri <alkhbiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:29:20 by alkhbiri          #+#    #+#             */
/*   Updated: 2025/03/01 14:22:46 by alkhbiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	cp_bonus(t_data *img)
{
	char	*cp;

	cp = ft_itoa(img->count++);
	mlx_put_image_to_window(img->mlx_ptr, img->win, img->img_wall, 0, 0);
	mlx_string_put(img->mlx_ptr, img->win, 20, 20, 15, cp);
	free (cp);
}

void	player_draw_bonus(char **lines, t_data *img)
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
				mlx_put_image_to_window(img->mlx_ptr,
					img->win, img->img_pface, j * 60, i * 60);
				break ;
			}
			j++;
		}
		i++;
	}
}

void	floor_drawing_bonus(char **lines, t_data *img)
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
			mlx_put_image_to_window((img)->mlx_ptr,
				(img)->win, (img)->img_floor, j * 60, i * 60);
			j++;
		}
		i++;
	}
}

t_mdata	monster_image(t_mdata *mon, void *mlx_ptr)
{
	int	w;
	int	h;

	mon->monster = mlx_xpm_file_to_image(mlx_ptr, "img/mface.xpm",
			&w, &h);
	mon->d_monster = mlx_xpm_file_to_image(mlx_ptr, "img/mback.xpm",
			&w, &h);
	mon->l_monster = mlx_xpm_file_to_image(mlx_ptr, "img/mleft.xpm",
			&w, &h);
	mon->r_monster = mlx_xpm_file_to_image(mlx_ptr, "img/mright.xpm",
			&w, &h);
	return (*mon);
}

t_data	putimage_bonus(t_data *img, void *mlx_ptr)
{
	img->mlx_ptr = mlx_ptr;
	img->img_door = mlx_xpm_file_to_image(img->mlx_ptr, "img/door.xpm",
			&img->img_width, &img->img_height);
	img->img_opendoor = mlx_xpm_file_to_image(img->mlx_ptr, "img/door_open.xpm",
			&img->img_width, &img->img_height);
	img->img_wall = mlx_xpm_file_to_image(img->mlx_ptr, "img/wall.xpm",
			&img->img_width, &img->img_height);
	img->img_floor = mlx_xpm_file_to_image(img->mlx_ptr, "img/floor.xpm",
			&img->img_width, &img->img_height);
	img->img_coin = mlx_xpm_file_to_image(img->mlx_ptr, "img/coin.xpm",
			&img->img_width, &img->img_height);
	img->img_pface = mlx_xpm_file_to_image(img->mlx_ptr, "img/face.xpm",
			&img->img_width, &img->img_height);
	img->img_pback = mlx_xpm_file_to_image(img->mlx_ptr, "img/back.xpm",
			&img->img_width, &img->img_height);
	img->img_pright = mlx_xpm_file_to_image(img->mlx_ptr, "img/right.xpm",
			&img->img_width, &img->img_height);
	img->img_pleft = mlx_xpm_file_to_image(img->mlx_ptr, "img/left.xpm",
			&img->img_width, &img->img_height);
	img->monster = mlx_xpm_file_to_image(img->mlx_ptr, "img/mface.xpm",
			&img->img_width, &img->img_height);
	img->win = mlx_new_window(img->mlx_ptr,
			img->img_width * line_len(*(img->lines)),
			img->img_height * map_len(img->lines), "so long");
	return (*img);
}
