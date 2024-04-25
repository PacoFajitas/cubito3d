/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-i <mlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:57:47 by meri              #+#    #+#             */
/*   Updated: 2024/04/25 20:44:02 by mlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_init_ttex(t_tex *t)
{
	t->index = 0;
	t->x = 0;
	t->y = 0;
	t->step = 0.0;
	t->pos = 0.0;
	t->hex_cel = 0x0;
	t->hex_cel = 0x0;
	t->height = 0;
	t->width = 0;
}

void	ft_init_text_pixel(t_data *data)
{
	int	i;
	if (data->text_pixel)
		ft_free_array((void **)data->text_pixel);
	data->text_pixel = ft_calloc(HEIGHT + 1, sizeof * data->text_pixel);
	if (!data->text_pixel)
		ft_error(data, "Error");
	i = 0;
	while (i < HEIGHT)
	{
		data->text_pixel[i] = ft_calloc(WIDTH + 1, sizeof(data->text_pixel));
		if (!data->text_pixel[i])
			ft_error(data, "Error");
		i++;
	}
}
