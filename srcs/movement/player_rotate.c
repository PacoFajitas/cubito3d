/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-i <mlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:05:34 by meri              #+#    #+#             */
/*   Updated: 2024/04/19 20:42:37 by mlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_rotate_lr(t_data *data)
{
	double	tmpX;

	tmpX = data->p->dirX;
	data->p->dirX = data->p->dirX * cos(data->p->rotate)
						- data->p->dirY * sin(data->p->rotate);
	data->p->dirY = tmpX * sin(data->p->rotate)
						+ data->p->dirY * cos(data->p->rotate);
	tmpX = data->p->planeX;
	data->p->planeX = data->p->planeX * cos(data->p->rotate)
						- data->p->planeY * sin(data->p->rotate);
	data->p->planeY = tmpX * sin(data->p->rotate)
						+ data->p->planeY * cos(data->p->rotate);
	return (1);
}

int	ft_rotate_player(t_data *data)
{
	int		moved;
	double	rotspeed;

	moved = 0;
	rotspeed = ROTSPEED * data->p->rotate;
	moved += ft_rotate_lr(data);
	return (moved);
}