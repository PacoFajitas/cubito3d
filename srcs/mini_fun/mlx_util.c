// 09
// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   mlx_func.c                                         :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: tfiguero <tfiguero@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/04/09 21:04:44 by tfiguero          #+#    #+#             */
// /*   Updated: 2024/04/09 21:08:30 by tfiguero         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "cub3D.h"

void	put_pixel(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}
void	new_image(t_data *data)
{
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	// if (!data->l->img.img)
		// ft_error(data, MLX_ERROR);
	data->img.addr = mlx_get_data_addr(data->img.img, 
					&data->img.bpp, &data->img.line_len, &data->img.endian);
	// if (!data->l->img.addr)
		// ft_error(data, MLX_ERROR);
	mlx_clear_window(data->mlx, data->win);
}
