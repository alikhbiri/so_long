/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkhbiri <alkhbiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:57:28 by alkhbiri          #+#    #+#             */
/*   Updated: 2025/02/13 15:19:35 by alkhbiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int map_len(char **lines)
{
    int ls;
    
    ls = 0;
    while (*lines)
    {
        ls++;
        lines++;
    }
    return (ls);
}

int line_len(char *lines)
{
    int ls;

    ls = 0;
    while (lines[ls])
        ls++;
    return (ls);
}

