/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-i <mlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:46:16 by mlopez-i          #+#    #+#             */
/*   Updated: 2024/04/25 20:41:30 by mlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
		if (r->dirY < 0)
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
			color = (color >> 1) & 8355711;
		if (color > 0)
			data->text_pixel[y][x] = color;
		y++;
	}
}