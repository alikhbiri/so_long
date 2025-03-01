/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkhbiri <alkhbiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:53:28 by alkhbiri          #+#    #+#             */
/*   Updated: 2025/03/01 13:35:57 by alkhbiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <mlx.h>

#define TILE_SIZE 60

typedef struct s_data
{
	void	*img_door;
	void	*img_opendoor;
	void	*img_wall;
	void	*img_floor;
	void	*img_pface;
	void	*img_pback;
	void	*img_pright;
	void	*img_pleft;
	void	*monster;
	void	*mlx_ptr;
	void	*win;
	int		img_width;
	int		img_height;
	int		count;
	char	**lines;
	void    *img_collectable;
}		t_data;

typedef struct p_pos
{
	int	x;
	int	y;
}		t_pos;

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		ft_strchr(const char *s, int c);
char	*ft_strdup(char *src);
size_t	ft_len(const char *str, int j);
char	*ft_join(char *s1, char *s2);
char	**ft_split(char const *s, char c);
void	ft_putstr_fd(char *s, int fd);
void	parssing(char **lines, char *maps);
char	**floodfill(char **lines, int x, int y);
char	*maps_s(char *line);
void	flood_test(char **lines);
void	name_error(char *name);
void	drawing(char *maps);
t_data	putimage(t_data *img, void *mlx_ptr);
int		move_player(int key, void *p);
t_pos	player_pos(char **lines, int k);
void	animation(t_data *img);
// void	portal_an(t_data *img);
int		map_len(char **lines);
int		line_len(char *lines);
int		collectable_checker(char **lines);
void	open_door(char **lines, t_data *map);
int		find_exit(char **lines);
void	len_check(char **lines);
void	floor_drawing(char **lines, t_data *img);
void	ft_putnbr(int n);
void	clearbuf(char **lines);
void	write_err(char *str);
void parssing(char **lines, char *maps);

// BONUS

typedef struct m_pos
{
	int	*x;
	int	*y;
	int	m;
}		t_mpos;

typedef struct m_data
{
	void	*l_monster;
	void	*r_monster;
	void	*d_monster;
	void	*monster;
}		t_mdata;

char	**floodfill_bonus(char **lines, int x, int y);
void	flood_test_bonus(char **lines);
char	*maps_s_bonus(char *line);
void	parssing_bonus(char **lines, char *maps);
t_data	putimage_bonus(t_data *img, void *mlx_ptr);
void	drawing_bonus(char *maps);
void	floor_drawing_bonus(char **lines, t_data *img);
int		move_player_bonus(int key, void *p);
t_pos	player_pos_bonus(char **lines, int k);
char	*ft_itoa(int n);
int		monster_move(void *param);
t_mdata	monster_image(t_mdata *mon, void *mlx_ptr);
void	name_error_bonus(char *name);
void	player_draw_bonus(char **lines, t_data *img);
void	cp_bonus(t_data *img);
t_mpos	monster_pos(char **lines, int i);
void	m_move_d(t_data	*img, int i);
void	m_move_u(t_data	*img, int i, t_mdata *mon);
void	m_move_r(t_data	*img, int i, t_mdata *mon);
void	m_move_l(t_data	*img, int i, t_mdata *mon);
void	write_err_bonus(char *str);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

#endif