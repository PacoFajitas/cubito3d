/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-i <mlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:46:16 by mlopez-i          #+#    #+#             */
/*   Updated: 2024/05/06 18:36:45 by mlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_convert_rgb_to_hex(int *rgb)
{
	return ((rgb[0] << 16) + (rgb[1] << 8) + (rgb[2]));
}

void	ft_put_pixel(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	ft_get_tex_color(t_img *tex, int texX, int texY)
{
	char	*pixel;

	pixel = tex->addr + (texY * tex->line_len + texX * (tex->bpp / 8));
	return (*(int *)pixel);
}

void	init_texture_img(t_data *data, t_img *image, char *path)
{
	ft_init_start_img(image);
	image->img = mlx_xpm_file_to_image(data->mlx, path, &image->width,
			&image->height);
	if (image->img == NULL)
		ft_error(data, "Error");
	image->addr = mlx_get_data_addr(image->img, &image->bpp,
			&image->line_len, &image->endian);
	if (image->addr == NULL)
		ft_error(data, "Error");
}
