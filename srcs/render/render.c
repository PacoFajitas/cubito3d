/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-i <mlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:27:44 by mlopez-i          #+#    #+#             */
/*   Updated: 2024/04/23 20:01:54 by mlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_render_raycast(t_data *data)
{
	ft_init_tray(&data->r);
	ft_raycasting(data);
}

int	ft_render(t_data *data)
{
	data->p->has_moved = ft_move_player(data);
	if (data->p->has_moved == 0)
		return (0);
	ft_render_raycast(data);
	//hay que actualizar la imagen solo si nos movemos
	//ft_render_images(data);
	return (0);
}