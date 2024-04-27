/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero <tfiguero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:51:30 by tfiguero          #+#    #+#             */
/*   Updated: 2024/04/27 23:15:50 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char *ft_clean_paths(char *src)
{
	char *dst;
	int	i;

	i = 0;
	while (src[0] && i < 2)
	{
		src++;
		i++;
	}
	while(src[0] && src[0] == ' ')
	{
		i++;
		src++;
	}
	dst = ft_strdup(src);
	if (!dst)
		return (NULL);
	while (i > 0)
	{
		src--;
		i--;
	}
	free(src);
	return (dst);	
}

int	ft_check_texts(t_map *m)
{
	if (!m->no || !m->so || !m->we || !m->ea)
		return (0);
	m->no = ft_strtrim(m->no, " ");
	m->so = ft_strtrim(m->so, " ");
	m->we = ft_strtrim(m->we, " ");
	m->ea = ft_strtrim(m->ea, " ");
	m->no = ft_clean_paths(m->no);
	m->so = ft_clean_paths(m->so);
	m->we = ft_clean_paths(m->we);
	m->ea = ft_clean_paths(m->ea);
	if (!m->no || !m->so || !m->we || !m->ea)
		return (0);
	if(access(m->no, F_OK) == -1 || access(m->so, F_OK) == -1
		|| access(m->we, F_OK) == -1 || access(m->ea, F_OK) == -1)
	{
		printf("cagas te\n");
		return (0);
	}
	return (1);
}

int	ft_check_rgb(t_map *m)
{
	char	**c;

	c = ft_split(m->f, ',');
	if (!c)
		return (0); //Error de malloc
	m->f_rgb[0] = ft_atoi(c[0]);
	m->f_rgb[1] = ft_atoi(c[1]);
	m->f_rgb[2] = ft_atoi(c[2]);
	ft_free_all(c, 3);
	if (m->f_rgb[0] < 0 || m->f_rgb[0] > 255
		|| m->f_rgb[1] < 0 || m->f_rgb[1] > 255
		|| m->f_rgb[2] < 0 || m->f_rgb[2] > 255)
		return (0); //Error de formato
	c = ft_split(m->c, ',');
	if (!c)
		return (0); //Error de malloc
	m->c_rgb[0] = ft_atoi(c[0]);
	m->c_rgb[1] = ft_atoi(c[1]);
	m->c_rgb[2] = ft_atoi(c[2]);
	ft_free_all(c, 3);
	if (m->c_rgb[0] < 0 || m->c_rgb[0] > 255
		|| m->c_rgb[1] < 0 || m->c_rgb[1] > 255
		|| m->c_rgb[2] < 0 || m->c_rgb[2] > 255)
		return (0); //Error de formato
	return (1);
}
