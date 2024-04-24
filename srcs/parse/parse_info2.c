/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero <tfiguero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:51:30 by tfiguero          #+#    #+#             */
/*   Updated: 2024/04/24 20:58:39 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
