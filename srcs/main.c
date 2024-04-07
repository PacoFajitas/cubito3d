/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-i <mlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:45:50 by tfiguero          #+#    #+#             */
/*   Updated: 2024/04/07 21:06:11 by mlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D.h"

//esto creo que no hace ni mierdas pq no esta mallokiado
// int	ft_get_map(t_map *m, int i, int j)
// {
// 	int x;
// 	int y;
// 	int k;
	
// 	x = 0;
// 	y = 0;
// 	k = 0;
// 	while (i < j)
// 	{
// 		while (m->file[i][k])
// 		{
// 			if (m->file[i][k] == ' ' || m->file[i][k] == '0')
// 				m->map[x][y] = 0;
// 			else if (m->file[i][k] == '1')
// 				m->map[x][y] = 1;
// 			else if (m->file[i][k] == '2')
// 				m->map[x][y] = 2;
// 			else if (m->file[i][k] == 'N' || m->file[i][k] == 'S' 
// 				|| m->file[i][k] == 'W' || m->file[i][k] == 'E')
// 				m->map[x][y] = m->file[i][k];
// 			else
// 			{
// 				ft_putstr_fd("invalid char is::", 1);
// 				ft_putchar_fd(m->file[i][j], 1);
// 				dprintf(1, "pos i::%d  pos j::%d\n", i, j);
// 				ft_putchar_fd('\n', 1);
// 				ft_putstr_fd("Invalid character in map\n", 2);
// 				return(1);
// 			}
// 			k++;
// 			y++;
// 		}
// 		while (y < m->width)
// 		{
// 			m->map[x][y] = 0;
// 			y++;
// 		}
// 		y = 0;
// 		k = 0;
// 		x++;
// 		i++;
// 	}
// 	return(0);
// }
//hacer que malloquee la nueva str y limpie la vieja
char	*ft_trim_final_spaces(char *str)
{
	int 	i;
	int		j;
	int		k;
	char	*ret;
	
	i = ft_strlen(str) - 1;
	j = 0;
	k = 0;
	if (!str)
		return(NULL);
	if(ft_strlen(str) == 1)
		return(str);
	// ft_putstr_fd(str, 1);
	while (str[i] == '\n')
		i--;
	while (str[i] && str[i] == ' ')
		i--;
	i += 1;
	ret = malloc(i + 1);
	while (str[k] && k < i)
	{
		ret[j] = str[k];
		k++;
		j++;
	}
	ret[j] = '\0';
	free(str);
	return(ret);
}
char	*ft_get_map_line(char	*str, int width)
{
	int		i;
	int		j;
	char	*ret;

	i = 1;
	j = 0;
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
char	*ft_put_spaces(int width)
{
	int i;
	char *ret;
	
	i = 0;
	ret = malloc(width + 1);
	while (i < width)
	{
		ret[i] = ' ';
		i++;
	}
	ret[i] = '\0';
	return(ret);
}

int	ft_get_map(t_map *m, int *i)
{
	int	x;
	int aux;

	aux = 0;
	x = *i;
	m->map = malloc(sizeof(char *) * (m->height + 1));
	m->map[0] = ft_put_spaces(m->width);
	aux++;
	while (aux < m->height - 2)
	{
		m->map[aux] = ft_get_map_line(m->file[x], m->width);
		aux++;
		x++;
	}
	m->map[aux] = ft_put_spaces(m->width);
	aux++;
	m->map[aux] = NULL;
	return(0);
}

void	ft_find_map_limits(t_map *m, int i)
{
	int	j;
	int initial_i;
	
	initial_i = i;
	while (m->file[i])
	{
		if (m->file[i][0] && m->file[i][0] == '\n')
			break;
		m->file[i] = ft_trim_final_spaces(m->file[i]);
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

char	*ft_clean_line(char *str)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	while (str[i] && str[i] == ' ')
		i++;
	ret = malloc(ft_strlen(str) - i + 1);
	while (str[i])
	{
		ret[j] = str[i];
		i++;
		j++;
	}
	free(str);
	ret[j] = '\0';
	return (ret);
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

int	ft_parse_map(t_map *m)
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
	//ft_print_data(m);
	return(ft_get_map(m, &i));
	
}

int	ft_count_tabs(char *line)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] == '\t')
			j++;
		i++;
	}
	return(j);
}
char	*ft_return_tabs_expanded(char *line, char *n_line)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (line[i])
	{
		if (line[i] == '\t')
		{
			n_line[k++] = ' ';
			n_line[k++] = ' ';
			n_line[k++] = ' ';
			n_line[k++] = ' ';
		}
		else
			n_line[k++] = line[i];
		i++;
	}
	n_line[k] = '\0';
	free(line);
	return(n_line);
}

char	*ft_expand_tabs(char *line)
{
	int i;
	int k;
	char *new_line;
	
	if (!line)
		return(NULL);
	i = ft_strlen(line);
	k = ft_count_tabs(line);
	new_line = malloc(sizeof(char) * (i + k + 1));
	if (!new_line)
	{
		perror("malloc");
		exit(1);
	}
	return(ft_return_tabs_expanded(line, new_line));
}

int	ft_count_lines(int fd)
{
	char *line;
	int i;
	
	i = 0;
	line = get_next_line(fd);
	while (line > 0)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return(i);
}

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

int	ft_check_map(char *map, t_map *m)
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
		exit(1);
	}
	i = ft_count_lines(fd);
	close(fd);
	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		perror("fd");
		exit(1);
	}
	ft_readfile(fd, m, i);
	close(fd);
	if (ft_parse_map(m))
		return (1);
	ft_print_array(m->map, 0);
	return(0);
}
void	ft_init_map(t_map *m)
{
	m->no = NULL;
	m->so = NULL;
	m->we = NULL;
	m->ea = NULL;
	m->f = NULL;
	m->c = NULL;
	m->map = NULL;
	m->file = NULL;
	m->height = 0;
	m->width = 0;
}

int main(int argc, char **argv)
{
	t_map m;
	
	if (argc != 2)
	{
		ft_putstr_fd("Please choose a map\n", 2);
		return(1);
	}
	ft_init_map(&m);
	if(ft_check_map(argv[1], &m))
	{
		//ft_free_m(&m);
		return(1);
	}
	return(0);
}