/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meri <meri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 19:50:01 by mlopez-i          #+#    #+#             */
/*   Updated: 2024/04/16 17:23:04 by meri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_key_pressed(int key, t_data *data)
{
//	if (key == ESC)
//		ft_exit(data);
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
	return (0);
}
