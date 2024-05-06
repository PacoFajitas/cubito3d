/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-i <mlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:05:34 by meri              #+#    #+#             */
/*   Updated: 2024/05/06 20:39:15 by mlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_rotate_lr(t_data *data, double rotspeed)
{
	t_player	*p;
	double		tmp_x;

	p = data->p;
	tmp_x = p->dir_x;
	p->dir_x = p->dir_x * cos(rotspeed) - p->dir_y * sin(rotspeed);
	p->dir_y = tmp_x * sin(rotspeed) + p->dir_y * cos(rotspeed);
	tmp_x = p->plane_x;
	p->plane_x = p->plane_x * cos(rotspeed) - p->plane_y * sin(rotspeed);
	p->plane_y = tmp_x * sin(rotspeed) + p->plane_y * cos(rotspeed);
	return (1);
}

int	ft_rotate_player(t_data *data, double rotate)
{
	int		moved;
	double	rotspeed;

	rotspeed = (double)(ROTSPEED * rotate);
	moved = 0;
	moved += ft_rotate_lr(data, rotspeed);
	return (moved);
}
