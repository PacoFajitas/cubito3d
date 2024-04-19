/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-i <mlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:42:37 by meri              #+#    #+#             */
/*   Updated: 2024/04/19 17:08:57 by mlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_init_img(t_data *data, t_img *img)
{
	ft_init_start_img(img);
	img->img = mlx_new_image(data->mlx, data->width, data->height);
//	if (!img->img)
//		ft_exit(data);
	img->addr = mlx_get_data_addr(img->img, &img->bpp,
				&img->line_len, &img->endian);
//	if (!img->img)
//		ft_exit(data);
}

void	ft_init_mlx(t_data *data)
{
	data->mlx = mlx_init();
//	if (!data->mlx)
//		ft_exit(data);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "cub3d");
//	if (!data->win)
//		ft_exit(data);
}