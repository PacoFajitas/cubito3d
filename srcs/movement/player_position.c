/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-i <mlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:54:22 by meri              #+#    #+#             */
/*   Updated: 2024/05/06 20:50:39 by mlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_valid_pos(t_data *data, double new_x, double new_y)
{
	double	limit;

	limit = 1.1;
	if (new_x < (limit * 2) || new_x >= data->m->width - limit)
		return (0);
	if (new_y < (limit * 2) || new_y >= data->m->height - limit)
		return (0);
	if (data->m->map[(int)new_y][(int)new_x] == '0'
		|| data->m->map[(int)new_y][(int)new_x] == data->p->dir)
		return (1);
	return (0);
}

int	ft_validate_move(t_data *data, double new_x, double new_y)
{
	int	moved;

	moved = 0;
	if (ft_valid_pos(data, new_x, data->p->pos_y))
	{
		data->m->map[(int)data->p->pos_y][(int)data->p->pos_x] = '0';
		data->p->pos_x = new_x;
		data->m->map[(int)data->p->pos_y][(int)new_x] = data->p->dir;
		moved = 1;
	}
	if (ft_valid_pos(data, data->p->pos_x, new_y))
	{
		data->m->map[(int)data->p->pos_y][(int)data->p->pos_x] = '0';
		data->p->pos_y = new_y;
		data->m->map[(int)new_y][(int)data->p->pos_x] = data->p->dir;
		moved = 1;
	}
	return (moved);
}
