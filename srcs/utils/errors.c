/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-i <mlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:42:21 by mlopez-i          #+#    #+#             */
/*   Updated: 2024/05/05 20:48:50 by mlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//frees arrays
void	ft_free_array(void **array)
{
	int	i;
	
	i = 0;
	while (array && array[i])
	{
		free(array[i]);
		i++;
	}
	if (array)
	{
		free(array);
		array = NULL;
	}
}

//	frees t_map
void	ft_free_tmap(t_map *m)
{
	if (m->map)
		ft_free_array((void **)m->map);
	if (m->file)
		ft_free_array((void **)m->file);
	if (m->no)
		free(m->no);
	if (m->so)
		free(m->so);
	if (m->ea)
		free(m->ea);
	if (m->we)
		free(m->we);
	if (m->f)
		free(m->f);
	if (m->c)
		free(m->c);
	if (m->p)
		m->p = NULL;
	free(m);
}

//	prints the error and frees everything
void	ft_error(t_data *data, char *msg)
{
	if (msg)
	{
		ft_putstr_fd("Cub3D: ", 2);
		ft_putendl_fd(msg, 2);
	}
	if (data->m)
	{
		ft_free_tmap(data->m);
		data->m = NULL;
	}
	if (data->p)
	{
		free(data->p);
		data->p = NULL;
	}
	if (data->img.img)
		mlx_destroy_image(data->mlx, &data->img.img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		free(data->mlx);
	exit(1);
}
