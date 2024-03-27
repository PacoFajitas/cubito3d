/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero <tfiguero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:45:50 by tfiguero          #+#    #+#             */
/*   Updated: 2024/03/27 21:51:06 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D.h"

// void	ft_parse_map(t_gen *gen, int ind)
// {
// 	int lim;

// 	lim = ft_strlen(gen->file[ind]);
// 	gen->map = malloc(sizeof(int *) * (lim + 1));
// 	while (gen->file[ind] != NULL && )
// 	{
		
// 	}
// }

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
char	**ft_return_tabs_expanded(char **line, char **n_line)
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

char	**ft_expand_tabs(char **line)
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

void	ft_readfile(int fd, t_gen *gen)
{
	char *line;
	int i;
	int j;
	
	i = 0;
	j = ft_count_lines(fd);
	gen->file = malloc(sizeof(char *) * (j + 1));
	line = get_next_line(fd);
	while (line > 0)
	{
		line = ft_expand_tabs(line);
		gen->file[i] = ft_strdup(line);
		free(line);
		if (!gen->file[i])
		{
			while (i >= 0)
				free(gen->file[i--]);
			free(gen->file);
			perror("malloc");
			exit(1);
		}
		i++;
		line = get_next_line(fd);
	}
	gen->file[i] = NULL;
	free(line);	
}

void	ft_check_map(char *map, t_gen *gen)
{
	int fd;
	if (ft_strcmp(ft_strchr(map, '.'), ".cub") != 0)
	{
		ft_putstr_fd("Please choose a .cub file\n", 2);
		exit(1);
	}
	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		perror("fd");
		exit(1);
	}
	ft_readfile(fd, gen);
	close(fd);
	ft_parse_map(gen);
}
void	ft_init_gen(t_gen *gen)
{
	gen->no = NULL;
	gen->so = NULL;
	gen->we = NULL;
	gen->ea = NULL;
	gen->f = -1;
	gen->c = -1;
	gen->map = NULL;
	gen->file = NULL;
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
	ft_check_map(argv[1], &gen);
	return(0);
}