/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meri <meri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 19:37:43 by mlopez-i          #+#    #+#             */
/*   Updated: 2024/04/16 17:18:20 by meri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_move_player_up(t_data *data)
{
	double	newX;
	double	newY;

	newX = data->p->posX + data->p->dirX * MOVESPEED;
	newY = data->p->posY + data->p->dirY * MOVESPEED;
	return (ft_validate_move(data, newX, newY));
}

int	ft_move_player_down(t_data *data)
{
	double	newX;
	double	newY;

	newX = data->p->posX - data->p->dirX * MOVESPEED;
	newY = data->p->posY - data->p->dirY * MOVESPEED;
	return (ft_validate_move(data, newX, newY));
}

int	ft_move_player_left(t_data *data)
{
	double	newX;
	double	newY;

	newX = data->p->posX + data->p->dirY * MOVESPEED;
	newY = data->p->posY - data->p->dirX * MOVESPEED;
	return (ft_validate_move(data, newX, newY));
}

int	ft_move_player_right(t_data *data)
{
	double	newX;
	double	newY;

	newX = data->p->posX - data->p->dirY * MOVESPEED;
	newY = data->p->posY + data->p->dirX * MOVESPEED;
	return (ft_validate_move(data, newX, newY));
}

int	ft_move_player(t_data *data)
{
	int	moved;

	moved = 0;
	if (data->p->move_y == 1)
		moved += ft_move_player_up(data);
	if (data->p->move_y == -1)
		moved += ft_move_player_down(data);
	if (data->p->move_x == 1)
		moved += ft_move_player_right(data);
	if (data->p->move_x == -1)
		moved += ft_move_player_left(data);
	return (moved);
}