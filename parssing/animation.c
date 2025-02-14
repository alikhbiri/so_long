/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkhbiri <alkhbiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:50:26 by alkhbiri          #+#    #+#             */
/*   Updated: 2025/02/13 15:19:40 by alkhbiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void an_loop(t_data *img, void *bp, char c)
{
    int i;
    int j;

    if (!bp)
    {
        ft_putstr_fd("Error: Image pointer is NULL\n", 2);
        return;
    }
    i = 0;
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
            }
            j++;
        }
        i++;
    }
}

// void	portal_an(t_data *img)
// {
// 	static int	n;
// 	void		*portal;
// 	char		*file_n;
// 	char		*path;

// 	n++;
// 	file_n = ft_strjoin(ft_itoa(n), "p.xpm");
// 	path = ft_strjoin("an/", file_n);
// 	portal = mlx_xpm_file_to_image(img->mlx_ptr, path,
// 			&img->img_width, &img->img_height);
// 	if (n == 13)
// 		n = 0;
// 	an_loop(img, portal, 'Q');
// 	free (file_n);
// 	free (path);
// }

// void	animation(t_data *img)
// {
// 	static int	n;
// 	void		*bat;
// 	char		*file_n;
// 	char		*path;

// 	n++;
// 	file_n = ft_strjoin(ft_itoa(n), ".xpm");
// 	path = ft_strjoin("an/", file_n);
// 	bat = mlx_xpm_file_to_image(img->mlx_ptr, path,
// 			&img->img_width, &img->img_height);
// 	if (n == 8)
// 		n = 0;
// 	an_loop(img, bat, 'E');
// 	free (file_n);
// 	free (path);
// }