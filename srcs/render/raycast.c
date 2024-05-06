/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-i <mlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 20:51:49 by mlopez-i          #+#    #+#             */
/*   Updated: 2024/05/06 18:37:05 by mlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_init_raycast(t_ray *r, t_player *p, int x)
{
	ft_init_tray(r);
	r->cameraX = 2 * x / (double)WIDTH - 1;
	r->dirX = p->dirX + p->planeX * r->cameraX;
	r->dirY = p->dirY + p->planeY * r->cameraX;
	r->mapX = (int)p->posX;
	r->mapY = (int) p->posY;
	if (r->dirX == 0.0)
		r->deltaX = 10000000.0;
	else
		r->deltaX = fabs(1 / r->dirX);
	if (r->dirY == 0.0)
		r->deltaY = 10000000.0;
	else
		r->deltaY  = fabs(1 / r->dirY);
}

void	ft_set_dda(t_ray *r, t_player *p)
{
	if (r->dirX < 0)
	{
		r->stepX = -1;
		r->sideX = (p->posX - r->mapX) * r->deltaX;
	}
	else
	{
		r->stepX = 1;
		r->sideX = (r->mapX + 1.0 - p->posX) * r->deltaX;
	}
	if (r->dirY < 0)
	{
		r->stepY = -1;
		r->sideY = (p->posY - r->mapY) * r->deltaY;
	}
	else
	{
		r->stepY = 1;
		r->sideY = (r->mapY + 1.0 - p->posY) * r->deltaY;
	}
}

void	ft_perform_dda(t_map *m, t_ray *r)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (r->sideX < r->sideY)
		{
			r->sideX += r->deltaX;
			r->mapX += r->stepX;
			if (r->dirX > 0)
				r->side = NORTH;
			else
				r->side = SOUTH;
		}
		else
		{
			r->sideY += r->deltaY;
			r->mapY += r->stepY;
			if (r->dirY > 0)
				r->side = WEST;
			else
				r->side = EAST;
		}
		if (m->map[r->mapY][r->mapX] == '1')
			hit = 1;
	}
}

void	ft_calculate_length(t_data *data, t_ray *r)
{
	if (r->side == 0 || r->side == 1)
		r->wall_dist = r->sideX - r->deltaX;
	else
		r->wall_dist = r->sideY - r->deltaY;
	r->lineH = (int)(HEIGHT / r->wall_dist) / 2;
	r->draw_start = -r->lineH / 2 + HEIGHT / 2;
	if (r->draw_start < 0)
		r->draw_start = 0;
	r->draw_end = r->lineH / 2 + HEIGHT / 2;
	if (r->draw_end >= HEIGHT)
		r->draw_end = HEIGHT - 1;
	if (r->side == 0 || r->side == 1)
		r->wallX = data->p->posY + r->wall_dist * r->dirY;
	else
		r->wallX = data->p->posX + r->wall_dist * r->dirX;
	r->wallX -= floor(r->wallX);
}

void	ft_set_tex_coord(t_data *data, t_ray *r, t_img *tex)
{
	data->texX = (int)(r->wallX * (double)tex[r->side].width);
	if (r->side == NORTH || r->side == EAST)
		data->texX = tex[r->side].width - data->texX - 1;
	data->tex_step = (double)tex[r->side].height / r->lineH;
	data->tex_pos = (r->draw_start - WIDTH / 2 + r->lineH / 2) * data->tex_step;
	
}

void	ft_draw_line(t_data *data, t_ray *r, t_img *tex, int x)
{
	int	y;
	int	texY;

	y = 0;
	while (y < HEIGHT)
	{
		if (y >= r->draw_start && y <= r->draw_end)
		{
			texY = (int)data->tex_pos & (tex[r->side].height - 1);
			ft_put_pixel(&data->img, x, y, ft_get_tex_color(&tex[r->side], data->texX, texY));
			data->tex_pos += data->tex_step;
		}
		else if (y < r->draw_start)
			ft_put_pixel(&data->img, x, y, ft_convert_rgb_to_hex(data->m->c_rgb));
		else if (y > r->draw_end)
			ft_put_pixel(&data->img, x, y, ft_convert_rgb_to_hex(data->m->f_rgb));
		y++;
	}
}

int	ft_raycasting(t_data *data)
{
	t_ray ray;
	int	x;

	x = 0;
	ft_init_tray(&ray);
	while (x < WIDTH)
	{
		ft_init_raycast(&ray, data->p, x);
		ft_set_dda(&ray, data->p);
		ft_perform_dda(data->m, &ray);
		ft_calculate_length(data, &ray);
		ft_set_tex_coord(data, &ray, data->text_img);
		ft_draw_line(data, &ray, data->text_img, x);
		// ft_update_texture_pixels(data, &data->t, &ray, x);
		x++;
	}
	return (1);
}