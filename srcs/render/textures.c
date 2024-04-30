/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero <tfiguero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:46:16 by mlopez-i          #+#    #+#             */
/*   Updated: 2024/04/30 20:37:23 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


void	init_texture_img(t_data *data, t_img *image, char *path)
{
	ft_init_start_img(image);
	image->img = mlx_xpm_file_to_image(data->mlx, path, &data->t.width,
			&data->t.height);
	// if (image->img == NULL)
		// ft_error
	image->addr = mlx_get_data_addr(image->img, &image->bpp,
			&image->line_len, &image->endian);
	return ;
}

 int	*xpm_to_img(t_data *data, char *path)
{
	t_img	tmp;
	int		*buffer;
	int		x;
	int		y;

	init_texture_img(data, &tmp, path);
	buffer = ft_calloc(1,
			sizeof * buffer * TEX_SIZE * TEX_SIZE);
	// if (!buffer)
	// 	ft_error()
	y = 0;
	while (y < TEX_SIZE)
	{
		x = 0;
		while (x < TEX_SIZE)
		{
			buffer[y * TEX_SIZE + x]
				= tmp.addr[y * TEX_SIZE + x];
				//= (int) tmp.addr + (y * tmp.line_len + x * (tmp.bpp / 8)); testeando esto da mas o menos igual
			++x;
		}
		y++;
	}
	mlx_destroy_image(data->mlx, tmp.img);
	return (buffer);
}

void	ft_get_texture_index(t_data *data, t_ray *r)
{
	if (r->side == 0)
	{
		if (r->dirX < 0)
			data->t.index = WEST;
		else
			data->t.index = EAST;
	}
	else
	{
		if (r->dirX < 0)
			data->t.index = NORTH;
		else
			data->t.index = SOUTH;
	}
}

void	ft_update_texture_pixels(t_data *data, t_tex *t, t_ray *r, int x)
{
	int	y;
	int	color;

	

	ft_get_texture_index(data, r);
	t->x = (int)(r->wallX * TEX_SIZE);
	if ((r->side == 0 && r->dirX < 0) || (r->side == 1 && r->dirY > 0))
		t->x = TEX_SIZE - t->x - 1;
	t->step = 1.0 * TEX_SIZE / r->lineH;
	t->pos = (r->draw_start - HEIGHT / 2 + r->lineH / 2) * t->step;
	y = r->draw_start;
	while (y < r->draw_end)
	{
		t->y = (int)t->pos & (TEX_SIZE - 1);
		t->pos += t->step;
		color = data->text[t->index][TEX_SIZE * t->y + t->x];
		if (t->index == NORTH || t->index == EAST)
			color = (color >> 1) & 0xff;
		if (color > 0)
			data->text_pixel[y][x] = color;
		y++;
	}
}
