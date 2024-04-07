/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero <tfiguero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:45:50 by tfiguero          #+#    #+#             */
/*   Updated: 2024/04/07 20:43:10 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D.h"

//esto creo que no hace ni mierdas pq no esta mallokiado
// int	ft_get_map(t_gen *gen, int i, int j)
// {
// 	int x;
// 	int y;
// 	int k;
	
// 	x = 0;
// 	y = 0;
// 	k = 0;
// 	while (i < j)
// 	{
// 		while (gen->file[i][k])
// 		{
// 			if (gen->file[i][k] == ' ' || gen->file[i][k] == '0')
// 				gen->map[x][y] = 0;
// 			else if (gen->file[i][k] == '1')
// 				gen->map[x][y] = 1;
// 			else if (gen->file[i][k] == '2')
// 				gen->map[x][y] = 2;
// 			else if (gen->file[i][k] == 'N' || gen->file[i][k] == 'S' 
// 				|| gen->file[i][k] == 'W' || gen->file[i][k] == 'E')
// 				gen->map[x][y] = gen->file[i][k];
// 			else
// 			{
// 				ft_putstr_fd("invalid char is::", 1);
// 				ft_putchar_fd(gen->file[i][j], 1);
// 				dprintf(1, "pos i::%d  pos j::%d\n", i, j);
// 				ft_putchar_fd('\n', 1);
// 				ft_putstr_fd("Invalid character in map\n", 2);
// 				return(1);
// 			}
// 			k++;
// 			y++;
// 		}
// 		while (y < gen->width)
// 		{
// 			gen->map[x][y] = 0;
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

int	ft_get_map(t_gen *gen, int *i)
{
	int	x;
	int aux;

	aux = 0;
	x = *i;
	gen->map = malloc(sizeof(char *) * (gen->height + 1));
	gen->map[0] = ft_put_spaces(gen->width);
	aux++;
	while (gen->file[x])
	{
		gen->map[aux] = ft_get_map_line(gen->file[x], gen->width);
		// gen->map[aux] = ft_strdup("");
		// gen->map[aux] = ft_strjoinfree(gen->map[aux], " ");
		// gen->map[aux] = ft_strjoinfree(gen->map[aux], gen->file[x]);
		// while((int)ft_strlen(gen->map[aux]) < gen->width)
		// 	gen->map[aux] = ft_strjoinfree(gen->map[aux], " ");
		aux++;
		x++;
	}
	gen->map[aux] = ft_put_spaces(gen->width);
	aux++;
	gen->map[aux] = NULL;
	return(0);
}

void	ft_find_map_limits(t_gen *gen, int i)
{
	int	j;
	int initial_i;
	
	initial_i = i;
	while (gen->file[i])
	{
		gen->file[i] = ft_trim_final_spaces(gen->file[i]);
		if (i > gen->height)
			gen->height =  i - initial_i;
		j = 0;
		while (gen->file[i] && gen->file[i][j])
		{
			if (j > gen->width)
				gen->width = j;
			j++;
		}
		i++;
	}
	gen->width += 3;
	gen->height += 3;
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

int	ft_find_info(t_gen *gen, int j, int line_len, int dot_len)
{
	while (gen->file[j])
	{
		gen->file[j] = ft_clean_line(gen->file[j]);
		line_len = ft_strlen(gen->file[j]);
		dot_len = ft_strlen(ft_strchr(gen->file[j], '.'));
		if(!ft_strncmp(gen->file[j], "NO", 2))
			gen->no = ft_substr(gen->file[j], line_len - dot_len, dot_len);
		else if(!ft_strncmp(gen->file[j], "SO", 2))
			gen->so = ft_substr(gen->file[j], line_len - dot_len, dot_len);
		else if(!ft_strncmp(gen->file[j], "WE", 2))
			gen->we = ft_substr(gen->file[j], line_len - dot_len, dot_len);
		else if(!ft_strncmp(gen->file[j], "EA", 2))
			gen->ea = ft_substr(gen->file[j], line_len - dot_len, dot_len);
		else if(!ft_strncmp(gen->file[j], "F", 1))
			gen->f = ft_get_fc(gen->file[j], 'F');
		else if(!ft_strncmp(gen->file[j], "C", 1))
			gen->c = ft_get_fc(gen->file[j], 'C');
		j++;
		if (gen->no && gen->so && gen->we && gen->ea && gen->f && gen->c)
			break ;
	}
	if (!gen->no || !gen->so || !gen->we || !gen->ea || !gen->f || !gen->c)
		return(0);
	return(j);
}

int	ft_parse_map(t_gen *gen)
{
	int	i;
	int j;
	
	j = 0;
	i = ft_find_info(gen, 0, 0, 0);
	if (i == 0)
		return(0);
	while(gen->file[j] && gen->file[j][0] == '\n')
		j++;
	ft_find_map_limits(gen, i);
	//ft_print_data(gen);
	return(ft_get_map(gen, &i));
	
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

void	ft_readfile(int fd, t_gen *gen, int j)
{
	char *line;
	int i;
	
	i = 0;
	gen->file = malloc(sizeof(char *) * (j + 1));
	line = get_next_line(fd);
	while (line > 0)
	{
		line = ft_expand_tabs(line);
		line = ft_strjoinfree(line, NULL);
		gen->file[i] = ft_strdup(line);
		free(line);
		if (!gen->file[i])
		{
			while (i >= 0)
				free(gen->file[i--]);//Liberar todo gen
			perror("malloc");
			exit(1);
		}
		i++;
		line = get_next_line(fd);
	}
	gen->file[i] = NULL;
	free(line);	
}

int	ft_check_map(char *map, t_gen *gen)
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
	ft_readfile(fd, gen, i);
	close(fd);
	if (ft_parse_map(gen))
		return (1);
	ft_print_array(gen->map, 0);
	return(0);
}
void	ft_init_gen(t_gen *gen)
{
	gen->no = NULL;
	gen->so = NULL;
	gen->we = NULL;
	gen->ea = NULL;
	gen->f = NULL;
	gen->c = NULL;
	gen->map = NULL;
	gen->file = NULL;
	gen->height = 0;
	gen->width = 0;
}

int main(int argc, char **argv)
{
	t_gen gen;
	
	if (argc != 2)
	{
		ft_putstr_fd("Please choose a map\n", 2);
		return(1);
	}
	ft_init_gen(&gen);
	if(ft_check_map(argv[1], &gen))
	{
		//ft_free_gen(&gen);
		return(1);
	}
	return(0);
}