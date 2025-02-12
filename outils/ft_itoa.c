/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkhbiri <alkhbiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:45:09 by alkhbiri          #+#    #+#             */
/*   Updated: 2025/02/10 14:45:11 by alkhbiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	size_j(long nb)
{
	int	j;

	j = 1;
	while (nb > 9)
	{
		nb = nb / 10;
		j++;
	}
	return (j);
}

char	*ft_itoa(int n)
{
	char	*r;
	int		j;
	long	nb;

	j = 1;
	nb = n;
	if (n < 0)
	{
		nb = -nb;
		j = 2;
	}
	r = (char *)malloc(sizeof(char) * (j = size_j(nb) + j));
	if (!r)
		return (NULL);
	j--;
	r[j] = '\0';
	while (j > 0)
	{
		j--;
		r[j] = (nb % 10) + 48;
		nb = nb / 10;
		if (j == 0 && n < 0)
			r[j] = '-';
	}
	return (r);
}