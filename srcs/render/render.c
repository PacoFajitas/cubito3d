/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-i <mlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:27:44 by mlopez-i          #+#    #+#             */
/*   Updated: 2024/05/06 20:41:58 by mlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_set_tex_coord(t_data *data, t_ray *r, t_img *tex)
{
	data->tex_x = (int)(r->wall_x * (double)tex[r->side].width);
	if (r->side == NORTH || r->side == EAST)
		data->tex_x = tex[r->side].width - data->tex_x - 1;
	data->tex_step = (double)tex[r->side].height / r->line_h;
	data->tex_pos = (r->draw_start - WIDTH / 2 + r->line_h / 2)
		* data->tex_step;
}

void	ft_draw_line(t_data *data, t_ray *r, t_img *tex, int x)
{
	int	y;
	int	tex_y;

	y = 0;
	while (y < HEIGHT)
	{
		if (y >= r->draw_start && y <= r->draw_end)
		{
			tex_y = (int)data->tex_pos & (tex[r->side].height - 1);
			ft_put_pixel(&data->img, x, y,
				ft_get_tex_color(&tex[r->side], data->tex_x, tex_y));
			data->tex_pos += data->tex_step;
		}
		else if (y < r->draw_start)
			ft_put_pixel(&data->img, x, y,
				ft_convert_rgb_to_hex(data->m->c_rgb));
		else if (y > r->draw_end)
			ft_put_pixel(&data->img, x, y,
				ft_convert_rgb_to_hex(data->m->f_rgb));
		y++;
	}
}

int	ft_render(t_data *data)
{
	t_img	img;

	img.img = NULL;
	ft_init_img(data, &img);
	data->img = img;
	mlx_clear_window(data->mlx, data->win);
	data->p->has_moved += ft_move_player(data);
	ft_raycasting(data);
	mlx_put_image_to_window(data->mlx, data->win, img.img, 0, 0);
	mlx_destroy_image(data->mlx, img.img);
	return (0);
}
