/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-i <mlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 19:50:01 by mlopez-i          #+#    #+#             */
/*   Updated: 2024/05/08 17:03:34 by mlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_key_pressed(int key, t_data *data)
{
	if (key == ESC)
		ft_exit(data);
	if (key == LEFTK)
		data->p->rotate = -1;
	if (key == RIGHTK)
		data->p->rotate = 1;
	if (key == W)
		data->p->move_y = 1;
	if (key == A)
		data->p->move_x = -1;
	if (key == S)
		data->p->move_y = -1;
	if (key == D)
		data->p->move_x = 1;
	// ft_print_array(data->m->map, 0);
	return (0);
}

int	ft_key_released(int key, t_data *data)
{
	if (key == ESC)
		ft_exit(data);
	if (key == LEFTK && data->p->rotate <= 1)
		data->p->rotate = 0;
	if (key == RIGHTK && data->p->rotate >= -1)
		data->p->rotate = 0;
	if (key == W && data->p->move_y == 1)
		data->p->move_y = 0;
	if (key == A && data->p->move_x == -1)
		data->p->move_x = 0;
	if (key == S && data->p->move_y == -1)
		data->p->move_y = 0;
	if (key == D && data->p->move_x == 1)
		data->p->move_x = 0;
	return (0);
}

void	ft_listen_for_input(t_data *data)
{
	mlx_hook(data->win, 2, (1L << 0), ft_key_pressed, data);
	mlx_hook(data->win, 3, (1L << 1), ft_key_released, data);
}
