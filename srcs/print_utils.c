/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-i <mlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:33:50 by meri              #+#    #+#             */
/*   Updated: 2024/04/07 21:07:18 by mlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D.h"

void ft_print_array(char **array, int i)
{
	while (array && array[i])
	{
		printf("|%s|\n", array[i]);
		i++;
	}
}

void	ft_print_map_data(t_map *m)
{
	ft_putstr_fd("data->no::", 1);
	if (m->no)
		ft_putstr_fd(m->no, 1);
	ft_putstr_fd("\ndata->so::", 1);
	if (m->so)
		ft_putstr_fd(m->so, 1);
	ft_putstr_fd("\ndata->ea::", 1);
	if (m->ea)
		ft_putstr_fd(m->ea, 1);
	ft_putstr_fd("\ndata->we::", 1);
	if (m->we)
		ft_putstr_fd(m->we, 1);
	ft_putstr_fd("\ndata->f::", 1);
	if (m->f)
		ft_putstr_fd(m->f, 1);
	ft_putstr_fd("\ndata->c::", 1);
	if (m->c)
		ft_putstr_fd(m->c, 1);
	ft_putstr_fd("\ndata->height::", 1);
	ft_putnbr_fd(m->height, 1);
	ft_putstr_fd("\ndata->width::", 1);
	ft_putnbr_fd(m->width, 1);
	ft_putchar_fd('\n', 1);
}
