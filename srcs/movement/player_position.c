/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-i <mlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:54:22 by meri              #+#    #+#             */
/*   Updated: 2024/04/23 17:47:04 by mlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//	first two is to check if pos is valid in map
//	last one is to check collision
int	ft_valid_pos(t_data *data, double newX, double newY)
{
	if (newX <= MOVESPEED || newX >= data->m->width - MOVESPEED)
		return (0);
	if (newY <= MOVESPEED || newY >= data->m->height - MOVESPEED)
		return (0);
	if (data->m->map[(int)newY][(int)newX] == '0'
		|| data->m->map[(int)newY][(int)newX] == data->p->dir)
		return (1);
	return (0);
}

int	ft_validate_move(t_data *data, double newX, double newY)
{
	int	moved;

	moved = 0;
	if (ft_valid_pos(data, newX, data->p->posY))
	{
		data->m->map[(int)data->p->posY][(int)data->p->posX] = '0';
		data->p->posX = newX;
		data->m->map[(int)data->p->posY][(int)newX] = data->p->dir;
		moved = 1;
	}
	if (ft_valid_pos(data, data->p->posX, newY))
	{
		data->m->map[(int)data->p->posY][(int)data->p->posX] = '0';
		data->p->posY = newY;
		data->m->map[(int)newY][(int)data->p->posX] = data->p->dir;
		moved = 1;
	}
	return (moved);
}
