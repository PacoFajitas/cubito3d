/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-i <mlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 21:05:03 by mlopez-i          #+#    #+#             */
/*   Updated: 2024/05/08 18:50:59 by mlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_find_map_limits(t_data *data, t_map *m, int i)
{
	int	j;
	int	initial_i;

	initial_i = i;
	while (m->file[i])
	{
		if (m->file[i][0] && m->file[i][0] == '\n')
			break ;
		m->file[i] = ft_trim_final_spaces(data, m->file[i], 0, 0);
		if (i > m->height)
			m->height = i - initial_i;
		j = 0;
		while (m->file[i] && m->file[i][j])
		{
			if (j > m->width)
				m->width = j;
			j++;
		}
		i++;
	}
	ft_more_boards(data, m, i);
	m->width += 3;
	m->height += 3;
}

void	ft_get_map(t_data *data, t_map *m, int *i, int aux)
{
	int	x;

	x = *i;
	m->map = malloc(sizeof(char *) * (m->height + 1));
	if (!m->map)
		ft_error(data, "Malloc error");
	m->map[0] = ft_put_spaces(m->width);
	if (!m->map[0])
		ft_error(data, "Malloc error");
	aux++;
	while (aux < m->height - 1)
	{
		m->map[aux] = ft_get_map_line(m->file[x], m->width, 1, 0);
		if (!m->map[aux])
			ft_error(data, "Malloc error");
		aux++;
		x++;
	}
	m->map[aux] = ft_put_spaces(m->width);
	if (!m->map[aux])
		ft_error(data, "Malloc error");
	aux++;
	m->map[aux] = NULL;
}

int	ft_check_map_spaces(t_map *m, int i, int j)
{
	if (i > 0 && (m->map[i - 1][j] != ' ' && m->map[i - 1][j] != '1'))
	{
		// printf("he entrado en el if1 en i:: %d j::%d y el map[i][j] es: %c\n", i, j, m->map[i][j]);
		return (0);
	}
	if (i < m->height - 1 && (m->map[i + 1][j] != ' ' && m->map[i + 1][j] != '1'))
	{
		// printf("he entrado en el if2 en i:: %d j::%d y el map[i][j] es: %c\n", i, j, m->map[i][j]);
		return (0);
	}
	if (j > 0 && (m->map[i][j - 1] != ' ' && m->map[i][j - 1] != '1'))
	{
		// printf("he entrado en el if3 en i:: %d j::%d y el map[i][j] es: %c\n", i, j, m->map[i][j]);
		return (0);
	}
	if (j < m->width - 1 && (m->map[i][j + 1] != ' ' && m->map[i][j + 1] != '1'))
	{
		// printf("he entrado en el if4 en i:: %d j::%d y el map[i][j] es: %c\n", i, j, m->map[i][j]);
		return (0);
	}
	// printf("no he entrado en ningun if en: i: %d, j: %d y el map[i][j] es: %c\n", i, j, m->map[i][j]);
	// ft_print_array(m->map, 0);
	return (1);
}

int	ft_check_map_chars(t_map *m, int i, int j, int *player)
{
	if (m->map[i][j] != ' ' && m->map[i][j] != '0' && m->map[i][j] != '1'
		&& m->map[i][j] != 'N' && m->map[i][j] != 'S'
		&& m->map[i][j] != 'W' && m->map[i][j] != 'E')
		return (0);
	if (m->map[i][j] == 'N' || m->map[i][j] == 'S' || m->map[i][j] == 'W'
		|| m->map[i][j] == 'E')
	{
		if (*player == 1)
			return (0);
		*player = 1;
		ft_init_player_pos(m->p, j, i, m->map[i][j]);
	}
	return (1);
}

void	ft_check_valid_map(t_data *data, t_map *m, int i, int j)
{
	int	player;

	player = 0;
	while (i < m->height)
	{
		j = 0;
		// printf("m->width: %d\n", m->width);
		while (j < m->width)
		{
			if (m->map[i][j] == ' ')
			{
				if (!ft_check_map_spaces(m, i, j))
					ft_error(data, "Invalid map");
			}
			if (!ft_check_map_chars(m, i, j, &player))
				ft_error(data, "Invalid map");
			j++;
		}
		i++;
	}
	if (player == 0)
		ft_error(data, "No player detected");
}
