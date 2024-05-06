/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-i <mlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:27:44 by mlopez-i          #+#    #+#             */
/*   Updated: 2024/05/06 18:06:55 by mlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_render(t_data *data)
{
	t_img	img;

	img.img = NULL;
	ft_init_img(data, &img);
	data->img = img;
	mlx_clear_window(data->mlx, data->win);

	data->p->has_moved += ft_move_player(data);
	// if (data->p->has_moved == 0)
	// 	return (0);
	ft_raycasting(data);
	mlx_put_image_to_window(data->mlx, data->win, img.img, 0, 0);
	mlx_destroy_image(data->mlx, img.img);
	return (0);
}
