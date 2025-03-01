/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkhbiri <alkhbiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:30:09 by alkhbiri          #+#    #+#             */
/*   Updated: 2025/03/01 14:06:50 by alkhbiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	m_move_u(t_data	*img, int i, t_mdata *mon)
{
	t_mpos	mp;

	mp = monster_pos(img->lines, -1);
	if (img->lines[mp.x[i] - 1][mp.y[i]] == '0')
	{
		img->lines[mp.x[i]][mp.y[i]] = '0';
		img->lines[mp.x[i] - 1][mp.y[i]] = 'M';
		mlx_put_image_to_window(img->mlx_ptr,
			img->win, img->img_floor, mp.y[i] * 60, mp.x[i] * 60);
		mlx_put_image_to_window(img->mlx_ptr,
			img->win, mon->d_monster, mp.y[i] * 60, (mp.x[i] - 1) * 60);
	}
	else if (img->lines[mp.x[i] - 1][mp.y[i]] == 'P')
		return (write(1, "Loser, what a shame", 19), exit (1));
	free (mp.x);
	free (mp.y);
}

void	m_move_d(t_data	*img, int i)
{
	t_mpos	mp;

	mp = monster_pos(img->lines, -1);
	if (img->lines[mp.x[i] + 1][mp.y[i]] == '0')
	{
		img->lines[mp.x[i]][mp.y[i]] = '0';
		img->lines[mp.x[i] + 1][mp.y[i]] = 'M';
		mlx_put_image_to_window(img->mlx_ptr,
			img->win, img->img_floor, mp.y[i] * 60, mp.x[i] * 60);
		mlx_put_image_to_window(img->mlx_ptr,
			img->win, img->monster, mp.y[i] * 60, (mp.x[i] + 1) * 60);
	}
	else if (img->lines[mp.x[i] + 1][mp.y[i]] == 'P')
		return (write(1, "Loser, what a shame", 19), exit (1));
	free (mp.x);
	free (mp.y);
}

void	m_move_r(t_data	*img, int i, t_mdata *mon)
{
	t_mpos	mp;

	mp = monster_pos(img->lines, -1);
	if (img->lines[mp.x[i]][mp.y[i] + 1] == '0')
	{
		img->lines[mp.x[i]][mp.y[i]] = '0';
		img->lines[mp.x[i]][mp.y[i] + 1] = 'M';
		mlx_put_image_to_window(img->mlx_ptr,
			img->win, img->img_floor, mp.y[i] * 60, mp.x[i] * 60);
		mlx_put_image_to_window(img->mlx_ptr,
			img->win, mon->r_monster, (mp.y[i] + 1) * 60, mp.x[i] * 60);
	}
	else if (img->lines[mp.x[i]][mp.y[i] + 1] == 'P')
		return (write(1, "Loser, what a shame", 19), exit (1));
	free (mp.x);
	free (mp.y);
}

void	m_move_l(t_data	*img, int i, t_mdata *mon)
{
	t_mpos	mp;

	mp = monster_pos(img->lines, -1);
	if (img->lines[mp.x[i]][mp.y[i] - 1] == '0')
	{
		img->lines[mp.x[i]][mp.y[i]] = '0';
		img->lines[mp.x[i]][mp.y[i] - 1] = 'M';
		mlx_put_image_to_window(img->mlx_ptr,
			img->win, img->img_floor, mp.y[i] * 60, mp.x[i] * 60);
		mlx_put_image_to_window(img->mlx_ptr,
			img->win, mon->l_monster, (mp.y[i] - 1) * 60, mp.x[i] * 60);
	}
	else if (img->lines[mp.x[i]][mp.y[i] - 1] == 'P')
		return (write(1, "Loser, what a shame", 19), exit (1));
	free (mp.x);
	free (mp.y);
}
