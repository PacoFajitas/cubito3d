/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-i <mlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 20:51:49 by mlopez-i          #+#    #+#             */
/*   Updated: 2024/04/19 21:28:10 by mlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_init_raycast(t_ray *r, t_player *p, int x)
{
	r->cameraX = 2 * x / (double)WIDTH - 1;
	r->dirX = p->dirX + p->planeX * r->cameraX;
	r->dirY = p->dirY + p->planeY * r->cameraX;
	r->mapX = (int)p->posX;
	r->mapY = (int) p->posY;
	r->deltaX = fabs(1 / r->dirX);
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
	while (r->hit == 0)
	{
		if (r->sideX < r->sideY)
		{
			r->sideX += r->deltaX;
			r->mapX += r->stepX;
			r->side = 0;
		}
		else
		{
			r->sideY += r->deltaY;
			r->mapY += r->stepY;
			r->side = 1;
		}
		if (m->map[r->mapY][r->mapX] > '0')
			r->hit = 1;
	}
}

int	ft_raycasting(t_data *data)
{
	int	x;

	x = 0;
	while (x < WIDTH)
	{
		ft_init_raycast(data->r, data->p, x);
		ft_set_dda(data->r, data->p);
		ft_perform_dda(data->m, data->r);
		//calcular la distancia de la recta(?)
		x++;
	}
	return (1);
}