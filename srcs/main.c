/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero <tfiguero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:45:50 by tfiguero          #+#    #+#             */
/*   Updated: 2024/04/24 21:00:58 by tfiguero         ###   ########.fr       */
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
	if(!ft_check_file(argv[1], data.m))
	{
		ft_putstr_fd("Error\n", 2);
		//ft_free_m(&m);
		return(1);
	}
	printf("File checked\n");
	// ft_print_array(data.m->file, 0);
	if (!ft_parse_info(data.m))
	{
		ft_putstr_fd("Error\n", 2);
		//ft_free_m(&m);
		return (1);
	}
	printf("Floor colors are %i %i %i\n", data.m->f_rgb[0], data.m->f_rgb[1], data.m->f_rgb[2]);
	printf("Ceiling colors are %i %i %i\n", data.m->c_rgb[0], data.m->c_rgb[1], data.m->c_rgb[2]);
	printf("Info parsed\n");
	// printf("valid map:::%i\n", ft_check_valid_map(data.m, 1, 1, 0));
	if (!ft_check_valid_map(data.m, 0, 0, 0))
	{
		ft_putstr_fd("Error\n", 2);
		exit(0);
		return (1);
	}
	printf("check ok\n");
	ft_init_mlx(&data);
	listen_for_input(&data);
	mlx_loop_hook(data.mlx, ft_render, &data);
	mlx_loop(data.mlx);
	// ft_print_map_data(&m);
	// ft_print_array(m.map, 0);
	return(0);
}
