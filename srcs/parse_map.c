/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-i <mlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 21:05:03 by mlopez-i          #+#    #+#             */
/*   Updated: 2024/04/09 19:01:15 by mlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_find_map_limits(t_map *m, int i)
{
	int	j;
	int initial_i;
	
	initial_i = i;
	while (m->file[i])
	{
		if (m->file[i][0] && m->file[i][0] == '\n')
			break;
		m->file[i] = ft_trim_final_spaces(m->file[i], 0, 0);
		if (i > m->height)
			m->height =  i - initial_i;
		j = 0;
		while (m->file[i] && m->file[i][j])
		{
			if (j > m->width)
				m->width = j;
			j++;
		}
		i++;
	}
	m->width += 3;
	m->height += 3;
}

char	*ft_get_map_line(char	*str, int width, int i, int j)
{
	char	*ret;

	ret = malloc(width + 1);
	if (!ret)
		return (NULL);
	ret[0] = ' ';
	while (i < width && str[j])
	{
		ret[i] = str[j];
		i++;
		j++;
	}
	while (i < width)
	{
		ret[i] = ' ';
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

int	ft_get_map(t_map *m, int *i)
{
	int	x;
	int aux;

	aux = 0;
	x = *i;
	m->map = malloc(sizeof(char *) * (m->height + 1));
	if (!m->map)
		return (0);
	m->map[0] = ft_put_spaces(m->width);
	aux++;
	while (aux < m->height - 1)
	{
		m->map[aux] = ft_get_map_line(m->file[x], m->width, 1, 0);
		aux++;
		x++;
	}
	m->map[aux] = ft_put_spaces(m->width);
	aux++;
	m->map[aux] = NULL;
	return(1);
}

int	ft_check_map_spaces(t_map *m, int i, int j)
{
	if (i > 0 && (m->map[i - 1][j] != ' ' && m->map[i - 1][j] != '1'))
		return (0);
	if (i < m->height && (m->map[i + 1][j] != ' ' && m->map[i + 1][j] != '1'))
		return (0);
	if (j > 0 && (m->map[i][j - 1] != ' ' && m->map[i][j - 1] != '1'))
		return (0);
	if (j < m->width && (m->map[i][j + 1] != ' ' && m->map[i][j + 1] != '1'))
		return (0);
	return (1);
}

int	ft_check_map_chars(t_map *m, int i, int j, int *player)
{
	if (m->map[i][j] != ' ' && m->map[i][j] != '0' && m->map[i][j] != '1'
		&& m->map[i][j] != 'N' && m->map[i][j] != 'S' 
		&& m->map[i][j] != 'W' && m->map[i][j] != 'E')
		return(0);
	if (m->map[i][j] == 'N' || m->map[i][j] == 'S' || m->map[i][j] == 'W'
		|| m->map[i][j] == 'E')
	{
		if (*player == 1)
		{
			printf("cagas te2\n");
			return(0);
		}
		*player = 1;
	}
	return (1);
}

int	ft_check_valid_map(t_map *m, int i, int j, int player)
{
	player = 0;
	while (i < m->height - 1)
	{
		j = 1;
		while (j < m->width - 1)
		{
			if (m->map[i][j] == ' ')
			{
				if (!ft_check_map_spaces(m, i, j))
					return (0);
			}
			if (!ft_check_map_chars(m, i, j, &player))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
