/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_direction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-i <mlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 19:38:10 by mlopez-i          #+#    #+#             */
/*   Updated: 2024/04/23 17:46:43 by mlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_init_player_pos(t_player *p, int x, int y, char c)
{
	p->dir = c;
	p->posX = x;
	p->posY = y;
	ft_init_player_dir(p);
}

void	ft_init_player_dir_ns(t_player *p)
{
	if (p->dir == 'N' || p->dir == 'S')
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
}

void	ft_init_player_dir(t_player *p)
{
	if (p->dir == 'N' || p->dir == 'S')
		ft_init_player_dir_ns(p);
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
