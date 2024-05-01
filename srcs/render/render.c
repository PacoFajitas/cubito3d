/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meri <meri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:27:44 by mlopez-i          #+#    #+#             */
/*   Updated: 2024/05/01 18:58:52 by meri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"



void	ft_set_image_pixel(t_img *image, int x, int y, int color)
{
	int	pixel;

	pixel = y * (image->line_len / 4) + x;
	image->addr[pixel] = color;
}

void	ft_set_frame_image_pixel(t_data *data, t_img *img, int x, int y)
{
	if (data->text_pixel[y][x] > 0)
	{
		put_pixel(img, x, y, 0x00FFFF);
		// ft_set_image_pixel(img,y , x, data->text_pixel[y][x]);
		// put_pixel(img, x, y, data->text_pixel[y][x]);
	}
	else if (y < HEIGHT / 2)
	{
		// ft_set_image_pixel(img, x, y, 0x00dc6400);
		put_pixel(img, x, y, data->t.hex_cel);
	}
	else if (y < HEIGHT -1)
	{
		put_pixel(img, x, y, data->t.hex_floor);
		// ft_set_image_pixel(img, x, y, 0x000011c9);
		// printf("x: %d, y: %d\n", x, y);
	}
}

void	ft_render_frame(t_data *data)
{
	t_img	img;
	int		x;
	int		y;
	
	img.img = NULL;
	ft_init_img(data, &img);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ft_set_frame_image_pixel(data, &img, x, y);
			x++;
		}
		y++;
	}
	//mlx_clear_window(data->mlx, data->win);
	mlx_put_image_to_window(data->mlx, data->win, img.img, 0, 0);
	mlx_destroy_image(data->mlx, img.img);
}

void	ft_render_raycast(t_data *data)
{
	ft_init_text_pixel(data);
	ft_init_tray(&data->r);
	ft_raycasting(data);
	ft_render_frame(data);
}

int	ft_render(t_data *data)
{
	data->p->has_moved += ft_move_player(data);
	if (data->p->has_moved == 0)
		return (0);
	ft_render_raycast(data);
	//hay que actualizar la imagen solo si nos movemos
	//ft_render_images(data);
	return (0);
}