/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-i <mlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 21:08:27 by mlopez-i          #+#    #+#             */
/*   Updated: 2024/04/09 21:07:23 by mlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_init_tmap(t_map *m, t_player *player)
{
	m->no = NULL;
	m->so = NULL;
	m->we = NULL;
	m->ea = NULL;
	m->f = NULL;
	m->c = NULL;
	m->map = NULL;
	m->file = NULL;
	m->height = 0;
	m->width = 0;
	m->p = player;
}

void	ft_init_player_pos(t_player *p, int x, int y)
{
	p->posX = x;
	p->posY = y;
	printf("player pos is:: x=%f  y=%f\n", p->posX, p->posY);	
}

void	ft_init_player_dir(t_player *p)
{
	
}
