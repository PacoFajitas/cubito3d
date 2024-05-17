/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero <tfiguero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 20:05:11 by mlopez-i          #+#    #+#             */
/*   Updated: 2024/05/09 17:26:05 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*ft_clean_paths(char *src)
{
	char	*dst;
	int		i;

	i = 0;
	while (src[0] && i < 2)
	{
		src++;
		i++;
	}
	while (src[0] && src[0] == ' ')
	{
		i++;
		src++;
	}
	dst = ft_strdup(src);
	while (i > 0)
	{
		src--;
		i--;
	}
	free(src);
	if (!dst)
		return (NULL);
	return (dst);
}

int	ft_check_texts(t_data *data, t_map *m)
{
	m->no = ft_strtrim(m->no, " ");
	m->so = ft_strtrim(m->so, " ");
	m->we = ft_strtrim(m->we, " ");
	m->ea = ft_strtrim(m->ea, " ");
	if (!m->no || !m->so || !m->we || !m->ea)
		ft_error(data, "Malloc error");
	m->no = ft_clean_paths(m->no);
	m->so = ft_clean_paths(m->so);
	m->we = ft_clean_paths(m->we);
	m->ea = ft_clean_paths(m->ea);
	if (!m->no || !m->so || !m->we || !m->ea)
		ft_error(data, "Malloc error");
	if (access(m->no, F_OK) == -1 || access(m->so, F_OK) == -1
		|| access(m->we, F_OK) == -1 || access(m->ea, F_OK) == -1)
		return (0);
	if (ft_strlen(m->no) < 5 || ft_strlen(m->so) < 5
		|| ft_strlen(m->we) < 5 || ft_strlen(m->ea) < 5)
		return (0);
	if (ft_strncmp(m->no + ft_strlen(m->no) - 4, ".xpm", 4) != 0
		|| ft_strncmp(m->so + ft_strlen(m->so) - 4, ".xpm", 4) != 0
		|| ft_strncmp(m->we + ft_strlen(m->we) - 4, ".xpm", 4) != 0
		|| ft_strncmp(m->ea + ft_strlen(m->ea) - 4, ".xpm", 4) != 0)
		return (0);
	return (1);
}
