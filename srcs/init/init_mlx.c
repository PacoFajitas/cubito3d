/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-i <mlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:42:37 by meri              #+#    #+#             */
/*   Updated: 2024/04/25 19:57:19 by mlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// void	ft_save_text(t_data *data, t_text *t, char *path)
// {
// 	t->img = mlx_xpm_file_to_image(data->mlx, path, &t->width, &t->height);
// 	// if (!t->img)
// 	// 	ft_error(data);
// 	t->addr = mlx_get_data_addr(data->mlx, &t->bpp, &t->line_len, &t->endian);
// 	// if (!t->addr)
// 	// 	ft_error(data);
// }

void	ft_init_start_img(t_img *img)
{
	img->img = NULL;
	img->addr = NULL;
	img->bpp = 0;
	img->line_len = 0;
	img->endian = 0;
}

void	ft_init_img(t_data *data, t_img *img)
{
	ft_init_start_img(img);
	img->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!img->img)
		ft_error(data, "Error");
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_len, &img->endian);
	if (!img->addr)
		ft_error(data, "Error");
}

void	ft_init_mlx(t_data *data)
{
	int	size;

	size = TEX_SIZE;
	data->mlx = mlx_init();
	if (!data->mlx)
		ft_error(data, "Error");
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "cub3d");
	if (!data->win)
		ft_error(data, "Error");
	data->text = ft_calloc(5, sizeof(data->text));
	if (!data->text)
		ft_error(data, "Error");
	data->text[NORTH] = mlx_xpm_file_to_image(data->mlx, data->m->no, &size, &size);
	data->text[SOUTH] = mlx_xpm_file_to_image(data->mlx, data->m->so, &size, &size);
	data->text[EAST] = mlx_xpm_file_to_image(data->mlx, data->m->ea, &size, &size);
	data->text[WEST] = mlx_xpm_file_to_image(data->mlx, data->m->we, &size, &size);
}
