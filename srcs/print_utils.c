/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meri <meri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:33:50 by meri              #+#    #+#             */
/*   Updated: 2024/04/04 18:22:24 by meri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D.h"

void ft_print_array(char **array, int i)
{
	while (array && array[i])
	{
		ft_putstr_fd(array[i], 1);
		i++;
	}
}

void	ft_print_data(t_gen *data)
{
	ft_putstr_fd("data->no::", 1);
	if (data->no)
		ft_putstr_fd(data->no, 1);
	ft_putstr_fd("\ndata->so::", 1);
	if (data->so)
		ft_putstr_fd(data->so, 1);
	ft_putstr_fd("\ndata->ea::", 1);
	if (data->ea)
		ft_putstr_fd(data->ea, 1);
	ft_putstr_fd("\ndata->we::", 1);
	if (data->we)
		ft_putstr_fd(data->we, 1);
	ft_putstr_fd("\ndata->f::", 1);
	if (data->f)
		ft_putstr_fd(data->f, 1);
	ft_putstr_fd("\ndata->c::", 1);
	if (data->c)
		ft_putstr_fd(data->c, 1);
	ft_putstr_fd("\ndata->height::", 1);
	ft_putnbr_fd(data->height, 1);
	ft_putstr_fd("\ndata->width::", 1);
	ft_putnbr_fd(data->width, 1);
	ft_putchar_fd('\n', 1);
}
