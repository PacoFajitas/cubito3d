/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-i <mlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:06:42 by mlopez-i          #+#    #+#             */
/*   Updated: 2024/05/08 18:56:11 by mlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_more_boards(t_data *data, t_map *m, int i)
{
	while (m->file[i])
	{
		if (!ft_is_valid_line(m->file[i]))
			ft_error(data, "Invalid map");
		i++;
	}
}
