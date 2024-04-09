/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero <tfiguero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 21:08:27 by mlopez-i          #+#    #+#             */
/*   Updated: 2024/04/09 23:42:30 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_init_tdata(t_data *data)
{
	data->m = malloc(sizeof(t_map));
	data->m->no = NULL;
	data->m->so = NULL;
	data->m->we = NULL;
	data->m->ea = NULL;
	data->m->f = NULL;
	data->m->c = NULL;
	data->m->map = NULL;
	data->m->height = 0;
	data->m->width = 0;
	data->m->p = malloc(sizeof(t_player));
	// if (!data->m->p)
		// ft_error(data, MLX_ERROR);
}

void	ft_init_player_pos(t_player *p, int x, int y)
{
	p->posX = x;
	p->posY = y;
	printf("player pos is:: x=%f  y=%f\n", p->posX, p->posY);	
}

void	ft_init_player_dir(t_player *p)
{
	if (p->dir == 'N')
	{
		p->dirX = 0;
		p->dirY = -1;
		p->planeX = 0;
		p->planeY = 0.66;
	}
	else if (p->dir == 'S')
	{
		p->dirX = 0;
		p->dirY = 1;
		p->planeX = -0.66;
		p->planeY = 0;
	}
	else if (p->dir == 'E')
	{
		p->dirX = 1;
		p->dirY = 0;
		p->planeX = 0;
		p->planeY = 0.66;
	}
	else if (p->dir == 'W')
	{
		p->dirX = -1;
		p->dirY = 0;
		p->planeX = 0;
		p->planeY = -0.66;
	}
}
