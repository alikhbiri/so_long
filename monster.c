/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkhbiri <alkhbiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:30:13 by alkhbiri          #+#    #+#             */
/*   Updated: 2025/03/01 13:39:55 by alkhbiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "so_long.h"

static int	monster_count(char **lines)
{
	int		i;
	int		j;
	int		m;

	i = 0;
	j = 0;
	m = 0;
	while (lines[i])
	{
		j = 0;
		while (lines[i][j])
		{
			if (lines[i][j] == 'M')
				m++;
			j++;
		}
		i++;
	}
	return (m);
}

t_mpos	monster_pos(char **lines, int i)
{
	t_mpos	mp;
	int		j;
	int		m;

	m = monster_count(lines);
	mp.x = malloc(sizeof(int) * m);
	mp.y = malloc(sizeof(int) * m);
	if (!mp.x || !mp.y)
		return (mp);
	m = 0;
	while (lines[++i])
	{
		j = -1;
		while (lines[i][++j])
		{
			if (lines[i][j] == 'M')
			{
				mp.x[m] = i;
				mp.y[m] = j;
				m++;
			}
		}
	}
	mp.m = m;
	return (mp);
}

void	move_to_kill(t_data *img, t_pos *pp, t_mpos *mp, t_mdata *mon)
{
	int	i;
	int	m;

	i = 0;
	m = monster_count(img->lines);
	while (i < m)
	{
		if (mp->x[i] > pp->x)
			m_move_u(img, i, mon);
		if (mp->y[i] > pp->y)
			m_move_l(img, i, mon);
		i++;
	}
	while (i > 0)
	{
		--i;
		if (mp->x[i] < pp->x)
			m_move_d(img, i);
		if (mp->y[i] < pp->y)
			m_move_r(img, i, mon);
	}
}

int	monster_move(void *param)
{
	t_data		*img;
	t_pos		pp;
	t_mpos		mp;
	t_mdata		mon;
	static int	j;

	img = param;
	if (j == 14000)
	{
		mon = monster_image(&mon, img->mlx_ptr);
		mp = monster_pos(img->lines, -1);
		pp = player_pos_bonus(img->lines, 0);
		move_to_kill(img, &pp, &mp, &mon);
		j = 0;
		free (mp.x);
		free (mp.y);
	}
	// if (j % 1000 == 0)
	// 	animation(img);
	// if (j % 500 == 0)
	// 	portal_an(img);
	j++;
	return (0);
}
