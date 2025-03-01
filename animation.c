/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkhbiri <alkhbiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:28:28 by alkhbiri          #+#    #+#             */
/*   Updated: 2025/03/01 14:11:43 by alkhbiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	an_loop(t_data *img, void *bp, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (img->lines[i])
	{
		j = 0;
		while (img->lines[i][j])
		{
			if (img->lines[i][j] == c)
			{
				mlx_put_image_to_window(img->mlx_ptr,
					img->win, img->img_floor, j * 60, i * 60);
				if (c == 'E')
					mlx_put_image_to_window(img->mlx_ptr,
						img->win, img->img_door, j * 60, i * 60);
				mlx_put_image_to_window(img->mlx_ptr,
					img->win, bp, j * 60, i * 60);
				break ;
			}
			j++;
		}
		i++;
	}	
}
