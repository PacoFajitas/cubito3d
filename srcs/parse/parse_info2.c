/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-i <mlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:51:30 by tfiguero          #+#    #+#             */
/*   Updated: 2024/05/06 20:32:47 by mlopez-i         ###   ########.fr       */
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
	return (1);
}

int	ft_check_rgb(t_data *data, t_map *m)
{
	char	**c;

	c = ft_split(m->f, ',');
	if (!c)
		ft_error(data, "Malloc error");
	m->f_rgb[0] = ft_atoi(c[0]);
	m->f_rgb[1] = ft_atoi(c[1]);
	m->f_rgb[2] = ft_atoi(c[2]);
	ft_free_all(c, 3);
	if (m->f_rgb[0] < 0 || m->f_rgb[0] > 255
		|| m->f_rgb[1] < 0 || m->f_rgb[1] > 255
		|| m->f_rgb[2] < 0 || m->f_rgb[2] > 255)
		return (0);
	c = ft_split(m->c, ',');
	if (!c)
		ft_error(data, "Malloc error");
	m->c_rgb[0] = ft_atoi(c[0]);
	m->c_rgb[1] = ft_atoi(c[1]);
	m->c_rgb[2] = ft_atoi(c[2]);
	ft_free_all(c, 3);
	if (m->c_rgb[0] < 0 || m->c_rgb[0] > 255
		|| m->c_rgb[1] < 0 || m->c_rgb[1] > 255
		|| m->c_rgb[2] < 0 || m->c_rgb[2] > 255)
		return (0);
	return (1);
}

char	*ft_get_map_line(char	*str, int width, int i, int j)
{
	char	*ret;

	ret = malloc(width + 1);
	if (!ret)
		return (NULL);
	ret[0] = ' ';
	while (i < width && str[j])
	{
		ret[i] = str[j];
		i++;
		j++;
	}
	while (i < width)
	{
		ret[i] = ' ';
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
