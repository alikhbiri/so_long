/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkhbiri <alkhbiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:33:25 by alkhbiri          #+#    #+#             */
/*   Updated: 2025/02/17 18:01:48 by alkhbiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char    **floodfill_bonus(char **lines, int x, int y)
{
    if (!lines[y] || lines[y][x] == 'S' || lines[y][x] == '1'
        || lines[y][x] == 'M' || lines[y][x] == 'Q')
        return (lines);
    lines[y][x] = 'S';
    lines = floodfill(lines, x + 1, y);
    lines = floodfill(lines, x - 1, y);
    lines = floodfill(lines, x, y + 1);
    lines = floodfill(lines, x, y - 1);
    return (lines);
}

char    *maps_s_bonus(char *line)
{
    int     map;
    char    *maps;

    map = open(line, O_RDWR, 0777);
    maps = NULL;
    while (1)
    {
        line = get_next_line(map);
        if (!line)
            break ;
        maps = ft_strjoin(maps, line);
        free(line);
    }
    close (map);
    return (maps);
}

void    flood_test_bonus(char **lines)
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
            if (lines[i][j] == 'E' || lines == 'C')
                write_err_bonus("non accessable path to items or exit");
            j++;
        }
        i++;
    }
}

t_pos   player_pos_bonus(char **lines, int k)
{
    int     i;
    int     j;
    t_pos   pp;
    
    i = 0;
    j = 0;
    while (lines[i])
    {
        j = 0;
        while (lines[i][j])
        {
            if (lines[i][j] == 'P')
            {
                k = 1;
                break ;
            }
            j++;
        }
        if (k == 1)
            break ;
        i++;
    }
    pp.x = i;
    pp.y = j;
    return (pp);
}