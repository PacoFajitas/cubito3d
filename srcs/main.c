/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-i <mlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:45:50 by tfiguero          #+#    #+#             */
/*   Updated: 2024/05/06 20:49:13 by mlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_parser(t_data *data, char **argv)
{
	ft_check_file(data, argv[1], data->m);
	ft_parse_info(data, data->m);
	ft_check_valid_map(data, data->m, 0, 0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_putstr_fd("Please choose a map\n", 2);
		return (1);
	}
	ft_init_tdata(&data);
	ft_parser(&data, argv);
	ft_init_mlx(&data);
	ft_listen_for_input(&data);
	mlx_loop_hook(data.mlx, ft_render, &data);
	mlx_loop(data.mlx);
	return (0);
}
