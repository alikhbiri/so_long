/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putimage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkhbiri <alkhbiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:26:28 by alkhbiri          #+#    #+#             */
/*   Updated: 2025/02/13 15:20:44 by alkhbiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    floor_drawing(char  **lines, t_data *img)
{
    int i;
    int j;

	img->count = 0;
    i = 0;
    while (lines[i])
    {
		j = 0;
        while (lines[i][j])
        {
			mlx_put_image_to_window(img->mlx_ptr,
                img->win, img->img_floor, j, i);
            j++;
        }
        i++;
    }
}

t_data putimage(t_data *img, void *mlx_ptr)
{
    char	**lines;

	lines = img->lines;
	img->mlx_ptr = mlx_ptr;
	img->img_door = mlx_xpm_file_to_image(img->mlx_ptr, "img/door.xpm",
			&img->img_width, &img->img_height);
	img->img_opendoor = mlx_xpm_file_to_image(img->mlx_ptr, "img/door_open.xpm",
			&img->img_width, &img->img_height);
	img->img_wall = mlx_xpm_file_to_image(img->mlx_ptr, "img/wall.xpm",
			&img->img_width, &img->img_height);
	img->img_floor = mlx_xpm_file_to_image(img->mlx_ptr, "img/floor.xpm",
			&img->img_width, &img->img_height);
	img->img_collectable = mlx_xpm_file_to_image(img->mlx_ptr, "img/collectable.xpm",
			&img->img_width, &img->img_height);
	img->img_pface = mlx_xpm_file_to_image(img->mlx_ptr, "img/face.xpm",
			&img->img_width, &img->img_height);
	img->img_pback = mlx_xpm_file_to_image(img->mlx_ptr, "img/back.xpm",
			&img->img_width, &img->img_height);
	img->img_pright = mlx_xpm_file_to_image(img->mlx_ptr, "img/right.xpm",
			&img->img_width, &img->img_height);
	img->img_pleft = mlx_xpm_file_to_image(img->mlx_ptr, "img/left.xpm",
			&img->img_width, &img->img_height);
	img->win = mlx_new_window(img->mlx_ptr, TILE_SIZE * line_len(*lines),
			TILE_SIZE * map_len(lines), "so long");
	return (*img);
}