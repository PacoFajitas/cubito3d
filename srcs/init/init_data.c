/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-i <mlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 21:08:27 by mlopez-i          #+#    #+#             */
/*   Updated: 2024/04/19 17:07:12 by mlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_init_start_img(t_img *img)
{
	img->img = NULL;
	img->addr = NULL;
	img->bpp = 0;
	img->line_len = 0;
	img->endian = 0;
}

void	ft_init_player(t_player *p)
{
	p->dir = '\0';
	p->posX = 0.0;
	p->posY = 0.0;
	p->dirX = 0.0;
	p->dirY = 0.0;
	p->planeX = 0.0;
	p->planeY = 0.0;
	p->rotate = 0;
	p->move_x = 0;
	p->move_y = 0;
}

void	ft_init_map(t_data *data, t_map *m)
{
	m->no = NULL;
	m->so = NULL;
	m->we = NULL;
	m->ea = NULL;
	m->f = NULL;
	m->c = NULL;
	m->map = NULL;
	m->height = 0;
	m->width = 0;
	m->p = data->p;
}

void	ft_init_tdata(t_data *data)
{
	data->m = malloc(sizeof(t_map));
	data->p = malloc(sizeof(t_player));
	// if (!data->m || !data->p)
		// ft_error(data, MLX_ERROR);
	ft_init_player(data->p);
	ft_init_map(data, data->m);
	data->height = HEIGHT;
	data->width = WIDTH;
}
