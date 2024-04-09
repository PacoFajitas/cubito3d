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

#include "../inc/cub3d.h"

void	put_pixel(t_data *f, int x, int y, int color)
{
	char	*dst;

	dst = f->l->img.addr + (y * f->l->img.line_len + x * (f->l->img.bpp / 8));
	*(unsigned int *)dst = color;
}
void	new_image(t_data *data)
{
	data->l->img.img = mlx_new_image(data->l->win.mlx_ptr, WIDTH, HEIGHT);
	// if (!data->l->img.img)
		// ft_error(data, MLX_ERROR);
	data->l->img.addr = mlx_get_data_addr(data->l->img.img, 
					&data->l->img.bpp, &data->l->img.line_len, &data->l->img.endian);
	// if (!data->l->img.addr)
		// ft_error(data, MLX_ERROR);
	mlx_clear_window(data->l->win.mlx_ptr, data->l->win.win_ptr);
}