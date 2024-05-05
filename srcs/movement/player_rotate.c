/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-i <mlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:05:34 by meri              #+#    #+#             */
/*   Updated: 2024/05/05 20:27:36 by mlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_rotate_lr(t_data *data, double rotspeed)
{
	t_player	*p;
	double		tmpX;

	p = data->p;
	tmpX = p->dirX;
	p->dirX = p->dirX * cos(rotspeed) - p->dirY * sin(rotspeed);
	p->dirY = tmpX * sin(rotspeed) + p->dirY * cos(rotspeed);
	tmpX = p->planeX;
	p->planeX = p->planeX * cos(rotspeed) - p->planeY * sin(rotspeed);
	p->planeY = tmpX * sin(rotspeed) + p->planeY * cos(rotspeed);
	return (1);
}

int	ft_rotate_player(t_data *data, double rotate)
{
	int		moved;
	double	rotspeed;

	rotspeed = (double)(ROTSPEED * rotate);
	moved = 0;
	moved += ft_rotate_lr(data, rotspeed);
	// printf("DATAPX  %f   DATAPY%f\n", data->p->dirX, data->p->dirY);
	// printf("DATAPLANEX  %f   DATAPLANEY%f\n", data->p->planeX, data->p->planeY);
	return (moved);
}