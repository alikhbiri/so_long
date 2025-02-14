/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkhbiri <alkhbiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:50:47 by alkhbiri          #+#    #+#             */
/*   Updated: 2025/02/13 15:31:55 by alkhbiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void map_control(char *maps, char **lines, int l)
{
    int i;
    int ls;

    i = 0;
    ls = map_len(lines) * (l + 1);
    while (maps[i])
    {
        if ((maps[i] == '\n' && maps[i + 1] == '\n') 
                || maps[0] == '\n' || maps[ls - 1] == '\n')
            write_err("map with empty line");
        if (maps[i] != 'P' && maps[i] != 'E' && maps[i] != 'C' 
                && maps[i] != '1' && maps[i] != '0' && maps[i] != '\n')
            write_err("map with unknown chars");
        i++;
    }
}

static void wall_error(char **lines)
{
    int i;
    int ls;

    i = 0;
    while (lines[0][i])
    {
        if (lines[0][i] != '1')
            write_err("Map is not surrounded by walls");
        i++;
    }
    i = 0;
    ls = line_len(lines[i]);
    while (lines[i])
    {
        if (lines[i][0] != '1' || lines[i][ls - 1] != '1')
            write_err("Map is not surrounded by walls");
        i++;
    }
    i = -1;
    ls = map_len(lines);
    while (lines[ls - 1][++i])
    {
        if (lines[ls - 1][i] != '1')
            write_err("Map is not surrounded by walls");
    }
}

void name_error(char *name)
{
    int ls;

    ls = line_len(name) - 1;
    if (name[ls] != 'r' || name[ls - 1] != 'e' 
            || name[ls - 2] != 'b' || name[ls - 3] != '.')
        write_err("Map extension must be '.ber'");
}

static void items_error(char **lines, int p, int e, int c)
{
    int i;
    int j;

    i = 0;
    while (lines[i])
    {
        j = 0;
        while (lines[i][j])
        {
            if (lines[i][j] == 'P')
                p++;
            else if (lines[i][j] == 'E')
                e++;
            else if (lines[i][j] == 'C')
                c++;
            j++;
        }
        i++;
    }
    if (p != 1 || e != 1 || c < 1)
        write_err("You must have only one P and E and at least one C");
}

void parssing(char **lines, char *maps)
{
    len_check(lines);
    map_control(maps, lines, line_len(lines[0]));
    wall_error(lines);
    items_error(lines, 0, 0, 0);
    if (line_len(*lines) > 136 || map_len(lines) > 136)
        write_err("Map too big");
}