/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkhbiri <alkhbiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:47:25 by alkhbiri          #+#    #+#             */
/*   Updated: 2025/02/01 13:47:25 by alkhbiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_strcmp(const char *str1, const char *str2)
{
    while (*str1 && (*str1 == *str2))
	{
        str1++;
        str2++;
    }
    return (unsigned char)*str1 - (unsigned char)*str2;
}