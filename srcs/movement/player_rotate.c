/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero <tfiguero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:05:34 by meri              #+#    #+#             */
/*   Updated: 2024/04/30 22:01:19 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_rotate_lr(t_data *data)
{
	double	tmpX;

	tmpX = data->p->dirX;
	data->p->dirX = data->p->dirX * cos(ROTSPEED)
						- data->p->dirY * sin(ROTSPEED);
	data->p->dirY = tmpX * sin(ROTSPEED)
						+ data->p->dirY * cos(ROTSPEED);
	tmpX = data->p->planeX;
	data->p->planeX = data->p->planeX * cos(ROTSPEED)
						- data->p->planeY * sin(ROTSPEED);
	data->p->planeY = tmpX * sin(ROTSPEED)
						+ data->p->planeY * cos(ROTSPEED);
	return (1);
}

int	ft_rotate_player(t_data *data)
{
	int		moved;
	double	rotspeed;

	moved = 0;
	rotspeed = ROTSPEED * data->p->rotate;
	moved += ft_rotate_lr(data);
	printf("DATAPX  %f   DATAPY%f\n", data->p->dirX, data->p->dirY);
	printf("DATAPLANEX  %f   DATAPLANEY%f\n", data->p->planeX, data->p->planeY);
	return (moved);
}