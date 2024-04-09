/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-i <mlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:45:50 by tfiguero          #+#    #+#             */
/*   Updated: 2024/04/09 21:03:03 by mlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D.h"

int main(int argc, char **argv)
{
	t_map 		m;
	t_player	p;
	if (argc != 2)
	{
		ft_putstr_fd("Please choose a map\n", 2);
		return(1);
	}
	ft_init_tmap(&m, &v);
	if(ft_check_file(argv[1], &m))
	{
		ft_putstr_fd("Error\n", 2);
		//ft_free_m(&m);
		return(1);
	}
	if (!ft_parse_info(&m))
	{
		ft_putstr_fd("Error\n", 2);
		//ft_free_m(&m);
		return (1);
	}
	if (!ft_check_valid_map(&m, 1, 1, 0))
	{
		ft_putstr_fd("Error\n", 2);
		//ft_free_m(&m);
		return (1);
	}
	// ft_print_map_data(&m);
	// ft_print_array(m.map, 0);
	return(0);
}
