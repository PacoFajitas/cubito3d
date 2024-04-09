/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-i <mlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 21:09:41 by mlopez-i          #+#    #+#             */
/*   Updated: 2024/04/07 21:29:36 by mlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_readfile(int fd, t_map *m, int j)
{
	char *line;
	int i;
	
	i = 0;
	m->file = malloc(sizeof(char *) * (j + 1));
	line = get_next_line(fd);
	while (line > 0)
	{
		line = ft_expand_tabs(line);
		line = ft_strjoinfree(line, NULL);
		m->file[i] = ft_strdup(line);
		free(line);
		if (!m->file[i])
		{
			while (i >= 0)
				free(m->file[i--]);//Liberar todo m
			perror("malloc");
			exit(1);
		}
		i++;
		line = get_next_line(fd);
	}
	m->file[i] = NULL;
	free(line);	
}

int	ft_check_file(char *map, t_map *m)
{
	int fd;
	int i;
	if (ft_strcmp(ft_strchr(map, '.'), ".cub") != 0)
	{
		ft_putstr_fd("Please choose a .cub file\n", 2);
		return(1);
	}
	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		perror("fd");
		return (1);
	}
	i = ft_count_lines(fd);
	close(fd);
	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		perror("fd");
		return (1);
	}
	ft_readfile(fd, m, i);
	close(fd);
	return(0);
}

char	*ft_get_fc(char *str, char c)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	if (str[i] && str[i] == c)
		i++;
	else
		return (NULL);
	while (str[i] && str[i] == ' ')
		i++;
	ret = malloc(ft_strlen(str) - i + 1);
	while (str[i])
	{
		ret[j] = str[i];
		i++;
		j++;
	}
	ret[j] = '\0';
	return (ret);
}

int	ft_find_info(t_map *m, int j, int line_len, int dot_len)
{
	while (m->file[j])
	{
		m->file[j] = ft_clean_line(m->file[j]);
		line_len = ft_strlen(m->file[j]);
		dot_len = ft_strlen(ft_strchr(m->file[j], '.'));
		if(!ft_strncmp(m->file[j], "NO", 2))
			m->no = ft_substr(m->file[j], line_len - dot_len, dot_len);
		else if(!ft_strncmp(m->file[j], "SO", 2))
			m->so = ft_substr(m->file[j], line_len - dot_len, dot_len);
		else if(!ft_strncmp(m->file[j], "WE", 2))
			m->we = ft_substr(m->file[j], line_len - dot_len, dot_len);
		else if(!ft_strncmp(m->file[j], "EA", 2))
			m->ea = ft_substr(m->file[j], line_len - dot_len, dot_len);
		else if(!ft_strncmp(m->file[j], "F", 1))
			m->f = ft_get_fc(m->file[j], 'F');
		else if(!ft_strncmp(m->file[j], "C", 1))
			m->c = ft_get_fc(m->file[j], 'C');
		j++;
		if (m->no && m->so && m->we && m->ea && m->f && m->c)
			break ;
	}
	if (!m->no || !m->so || !m->we || !m->ea || !m->f || !m->c)
		return(0);
	return(j);
}

int	ft_parse_info(t_map *m)
{
	int	i;
	int j;
	
	j = 0;
	i = ft_find_info(m, 0, 0, 0);
	if (i == 0)
		return(0);
	while (m->file[i] && m->file[i][0] && m->file[i][0] == '\n')
		i++;
	ft_find_map_limits(m, i);
	return(ft_get_map(m, &i));
}
