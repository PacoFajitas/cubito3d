/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-i <mlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:42:37 by meri              #+#    #+#             */
/*   Updated: 2024/04/23 20:01:39 by mlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_save_text(t_data *data, t_text *t, char *path)
{
	t->img = mlx_xpm_file_to_image(data->mlx, path, &t->width, &t->height);
	// if (!t->img)
	// 	ft_error(data);
	t->addr = mlx_get_data_addr(data->mlx, &t->bpp, &t->line_len, &t->endian);
	// if (!t->addr)
	// 	ft_error(data);
}

void	ft_init_img(t_data *data)
{
	ft_init_start_img(&data->img);
	data->img.img = mlx_new_image(data->mlx, data->width, data->height);
//	if (!img->img)
//		ft_exit(data);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp,
				&data->img.line_len, &data->img.endian);
//	if (!img->addr)
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
	ft_init_img(data);
	ft_save_text(data, &data->text[0], data->m->no);
	ft_save_text(data, &data->text[1], data->m->so);
	ft_save_text(data, &data->text[2], data->m->we);
	ft_save_text(data, &data->text[3], data->m->ea);
}
