/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkhbiri <alkhbiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:29:52 by alkhbiri          #+#    #+#             */
/*   Updated: 2025/03/05 12:42:17 by alkhbiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	j = -1;
	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_len(s1, 1) + ft_len(s2, 1) + 1));
	if (!str)
		return (NULL);
	while (s1[++j])
		str[j] = s1[j];
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	free (s1);
	return (str);
}

char	*ft_join(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1)
		return (ft_substr(s2, 0, ft_len(s2, 0)));
	if (!s2)
		return (ft_substr(s1, 0, ft_len(s1, 0)));
	j = 0;
	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_len(s1, 1) + ft_len(s2, 0) + 1));
	if (!str)
		return (NULL);
	while (s1[j])
	{
		str[j] = s1[j];
		j++;
	}
	while (s2[i])
	{
		str[j++] = s2[i++];
		if (s2[i - 1] == '\n')
			break ;
	}
	return (str[j] = '\0', str);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;
	size_t	j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (start > ft_len(s, 1) || len == 0)
		return (ft_strdup(""));
	if (len > ft_len(s, 1) - start)
		len = ft_len(s, 1) - start;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
			str[j++] = s[i];
		i++;
	}
	str[j] = '\0';
	return (str);
}

int	ft_strchr(const char *s, int c)
{
	int		i;
	char	*r;

	if (!s)
		return (0);
	r = (char *)s;
	i = 0;
	while (r[i] != (char)c && r[i])
		i++;
	if (r[i] == (char)c)
		return (i + 1);
	return (0);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	if (!src)
		return (ft_strdup(""));
	i = ft_len(src, 1);
	dest = (char *)malloc(sizeof(char) * i + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
