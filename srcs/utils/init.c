/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-i <mlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 21:08:27 by mlopez-i          #+#    #+#             */
/*   Updated: 2024/04/11 19:38:26 by mlopez-i         ###   ########.fr       */
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


