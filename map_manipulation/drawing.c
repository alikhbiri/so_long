/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkhbiri <alkhbiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:10:50 by alkhbiri          #+#    #+#             */
/*   Updated: 2025/02/17 17:07:44 by alkhbiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    wall_draw(char **lines, t_data *img)
{
    int i;
    int j;

    i = 0;
    j = 0;
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

void    collectable_draw(char **lines, t_data *img)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (lines[i])
    {
        j = 0;
        while (lines[i][j])
        {
            if (lines[i][j] == 'C')
                mlx_put_image_to_window((img)->mlx_ptr,
                    (img)->win, (img)->img_collectable, j, i);
            j++;   
        }
        i++;
    }
}

void    door_draw(char **lines, t_data *img)
{
    int i;
    int j;

    i = 0;
    j = 0;
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

void    player_draw(char **lines, t_data *img)
{
    int i;
    int j;

    i = 0;
    j = 0;
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
    int width;
    int height;

	img.mlx_ptr = mlx_init();
    if (!img.mlx_ptr)
    {
        exit(0);
    }
	img.lines = ft_split(maps, '\n');
	img.count = 1;
	img = putimage(&img, img.mlx_ptr);
    img.img_floor = mlx_xpm_file_to_image(img.mlx_ptr, "img/floor.xpm",
        &width, &height);
    if (!img.img_floor)
    {
        printf("here\n");
        exit(0);
    }
    floor_drawing(img.lines, &img);
	wall_draw(img.lines, &img);
	door_draw(img.lines, &img);
	player_draw(img.lines, &img);
	collectable_draw(img.lines, &img);
    // exit(0);
	mlx_hook(img.win, 2, 0, move_player, &img);
	mlx_loop(img.mlx_ptr);
}