/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-i <mlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 20:51:49 by mlopez-i          #+#    #+#             */
/*   Updated: 2024/05/06 20:49:41 by mlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_init_raycast(t_ray *r, t_player *p, int x)
{
	ft_init_tray(r);
	r->camera_x = 2 * x / (double)WIDTH - 1;
	r->dir_x = p->dir_x + p->plane_x * r->camera_x;
	r->dir_y = p->dir_y + p->plane_y * r->camera_x;
	r->map_x = (int)p->pos_x;
	r->map_y = (int) p->pos_y;
	if (r->dir_x == 0.0)
		r->delta_x = 10000000.0;
	else
		r->delta_x = fabs(1 / r->dir_x);
	if (r->dir_y == 0.0)
		r->delta_y = 10000000.0;
	else
		r->delta_y = fabs(1 / r->dir_y);
}

void	ft_set_dda(t_ray *r, t_player *p)
{
	if (r->dir_x < 0)
	{
		r->step_x = -1;
		r->side_x = (p->pos_x - r->map_x) * r->delta_x;
	}
	else
	{
		r->step_x = 1;
		r->side_x = (r->map_x + 1.0 - p->pos_x) * r->delta_x;
	}
	if (r->dir_y < 0)
	{
		r->step_y = -1;
		r->side_y = (p->pos_y - r->map_y) * r->delta_y;
	}
	else
	{
		r->step_y = 1;
		r->side_y = (r->map_y + 1.0 - p->pos_y) * r->delta_y;
	}
}

void	ft_perform_dda(t_map *m, t_ray *r, int hit)
{
	while (hit == 0)
	{
		if (r->side_x < r->side_y)
		{
			r->side_x += r->delta_x;
			r->map_x += r->step_x;
			if (r->dir_x > 0)
				r->side = NORTH;
			else
				r->side = SOUTH;
		}
		else
		{
			r->side_y += r->delta_y;
			r->map_y += r->step_y;
			if (r->dir_y > 0)
				r->side = WEST;
			else
				r->side = EAST;
		}
		if (m->map[r->map_y][r->map_x] == '1')
			hit = 1;
	}
}

void	ft_calculate_length(t_data *data, t_ray *r)
{
	if (r->side == 0 || r->side == 1)
		r->wall_dist = r->side_x - r->delta_x;
	else
		r->wall_dist = r->side_y - r->delta_y;
	r->line_h = (int)(HEIGHT / r->wall_dist);
	r->draw_start = -r->line_h / 2 + HEIGHT / 2;
	if (r->draw_start < 0)
		r->draw_start = 0;
	r->draw_end = r->line_h / 2 + HEIGHT / 2;
	if (r->draw_end >= HEIGHT)
		r->draw_end = HEIGHT - 1;
	if (r->side == 0 || r->side == 1)
		r->wall_x = data->p->pos_y + r->wall_dist * r->dir_y;
	else
		r->wall_x = data->p->pos_x + r->wall_dist * r->dir_x;
	r->wall_x -= floor(r->wall_x);
}

int	ft_raycasting(t_data *data)
{
	t_ray	ray;
	int		x;

	x = 0;
	ft_init_tray(&ray);
	while (x < WIDTH)
	{
		ft_init_raycast(&ray, data->p, x);
		ft_set_dda(&ray, data->p);
		ft_perform_dda(data->m, &ray, 0);
		ft_calculate_length(data, &ray);
		ft_set_tex_coord(data, &ray, data->text_img);
		ft_draw_line(data, &ray, data->text_img, x);
		x++;
	}
	return (1);
}
