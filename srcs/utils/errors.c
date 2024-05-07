/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero <tfiguero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:42:21 by mlopez-i          #+#    #+#             */
/*   Updated: 2024/05/07 22:53:10 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void ft_print_pointers(t_data *data, int fd)
{
	int i;

	i = 0;
	dprintf(fd, "mlx: %p\n", data->mlx);
	dprintf(fd, "win: %p\n", data->win);
	dprintf(fd, "text_img: %p\n", data->text_img);
	// printf("text_img: %p\n", data->img);
	dprintf(fd, "img->img: %p\n", data->img.img);
	dprintf(fd, "img->addr: %p\n", data->img.addr);
	dprintf(fd, "img->width: %d\n", data->img.width);
	dprintf(fd, "img->height: %d\n", data->img.height);
	dprintf(fd, "img->bpp: %d\n", data->img.bpp);
	dprintf(fd, "img->line_len: %d\n", data->img.line_len);
	dprintf(fd, "img->endian: %d\n", data->img.endian);
	dprintf(fd, "m: %p\n", data->m);
	dprintf(fd, "m->file: %p\n", data->m->file);
	dprintf(fd, "m->no: %p\n", data->m->no);
	dprintf(fd, "m->so: %p\n", data->m->so);
	dprintf(fd, "m->we: %p\n", data->m->we);
	dprintf(fd, "m->ea: %p\n", data->m->ea);
	dprintf(fd, "m->f: %p\n", data->m->f);
	dprintf(fd, "m->c: %p\n", data->m->c);
	dprintf(fd, "m->map: %p\n", data->m->map);
	dprintf(fd, "m->p: %p\n", data->m->p);
	dprintf(fd, "p: %p\n", data->p);
}

//frees arrays
void	ft_free_array(void **array)
{
	int	i;

	i = 0;
	while (array && array[i])
	{
		printf("freeing array[%d]\n", i);
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
	if (m->map && m->map != NULL)
		ft_free_array((void **)m->map);
	if (m->file && m->file != NULL)
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
	ft_putendl_fd("Error", 2);
	if (msg)
	{
		ft_putstr_fd("Cub3D: ", 2);
		ft_putendl_fd(msg, 2);
	}
	ft_exit(data);
}

void	ft_exit(t_data *data)
{
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
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		free(data->mlx);
	exit(1);
}
