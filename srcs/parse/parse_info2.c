/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero <tfiguero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:51:30 by tfiguero          #+#    #+#             */
/*   Updated: 2024/05/07 21:52:21 by tfiguero         ###   ########.fr       */
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
