/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meri <meri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:54:22 by meri              #+#    #+#             */
/*   Updated: 2024/04/16 17:07:13 by meri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//	first two is to check if pos is valid in map
//	last one is to check collision
int	ft_valid_pos(t_data *data, double newX, double newY)
{
	if (newX < 0.25 || newX >= data->m->width - 1.25)
		return (0);
	if (newY < 0.25 || newY >= data->m->height - 1.25)
		return (0);
	if (data->m->map[(int)newX][(int)newY] == '0')
		return (1);
	return (0);
}

int	ft_validate_move(t_data *data, double newX, double newY)
{
	int	moved;

	moved = 0;
	if (ft_valid_pos(data, newX, data->p->posY))
	{
		data->p->posX = newX;
		moved = 1;
	}
	if (ft_valid_pos(data, data->p->posX, newY))
	{
		data->p->posY = newY;
		moved = 1;
	}
	return (moved);
}
