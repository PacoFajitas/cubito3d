/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-i <mlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:45:50 by tfiguero          #+#    #+#             */
/*   Updated: 2024/05/05 20:46:46 by mlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D.h"

int main(int argc, char **argv)
{
	t_data data;

	if (argc != 2)
	{
		ft_putstr_fd("Please choose a map\n", 2);
		return(1);
	}
	ft_init_tdata(&data);
	if(!ft_check_file(argv[1], data.m) || !ft_parse_info(data.m)
		|| !ft_check_valid_map(data.m, 0, 0, 0))
	{
		ft_error(&data, "Error");
		return(1);
	}
	ft_init_mlx(&data);
	listen_for_input(&data);
	mlx_loop_hook(data.mlx, ft_render, &data);
	mlx_loop(data.mlx);
	// ft_print_map_data(&m);
	// ft_print_array(m.map, 0);
	return(0);
}
