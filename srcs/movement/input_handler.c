/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-i <mlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 19:50:01 by mlopez-i          #+#    #+#             */
/*   Updated: 2024/04/23 21:02:32 by mlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_key_pressed(int key, t_data *data)
{
	if (key == ESC)
		exit(0);	//haz cosas (ft exit y eso)
	if (key == LEFTK)
		data->p->rotate -= 1;
	if (key == RIGHTK)
		data->p->rotate += 1;
	if (key == W)
		data->p->move_y = 1;
	if (key == A)
		data->p->move_x = -1;
	if (key == S)
		data->p->move_y = -1;
	if (key == D)
		data->p->move_x = 1;
	// ft_move_player(data);
	// ft_print_array(data->m->map, 0);
	// printf("player is x::%f  y::%f\n", data->p->posX, data->p->posY);
	// printf("move_y::%d     move_x::%d\n", data->p->move_y, data->p->move_x);
	return (0);
}

int	ft_key_released(int key, t_data *data)
{
//	if (key == ESC)
//		ft_exit(data);
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
	// printf("move_y::%d     move_x::%d\n", data->p->move_y, data->p->move_x);
	return (0);
}

void	listen_for_input(t_data *data)
{
	mlx_hook(data->win, 2, (1L << 0), ft_key_pressed, data);
	mlx_hook(data->win, 3, (1L << 1), ft_key_released, data);
	// ft_print_array(data->m->map, 0);
}
