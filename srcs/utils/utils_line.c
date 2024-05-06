/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-i <mlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 21:19:02 by mlopez-i          #+#    #+#             */
/*   Updated: 2024/05/06 20:48:07 by mlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_count_lines(int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line > 0)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (i);
}

char	*ft_put_spaces(int width)
{
	int		i;
	char	*ret;

	i = 0;
	ret = malloc(width + 1);
	if (!ret)
		return (NULL);
	while (i < width)
	{
		ret[i] = ' ';
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_trim_final_spaces(t_data *data, char *str, int j, int k)
{
	int		i;
	char	*ret;

	if (!str)
		ft_error(data, "Malloc error");
	i = ft_strlen(str) - 1;
	if (ft_strlen(str) == 1)
		return (str);
	if (str[i] == '\n')
		i--;
	while (i > 0 && str[i] && str[i] == 32)
		i--;
	i += 1;
	ret = malloc(i + 1);
	if (!ret)
		ft_error(data, "Malloc error");
	while (str[k] && k < i)
	{
		ret[j] = str[k];
		k++;
		j++;
	}
	ret[j] = '\0';
	free(str);
	return (ret);
}

char	*ft_clean_line(char *str)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	while (str[i] && (str[i] == ' '))
		i++;
	ret = malloc(ft_strlen(str) - i + 1);
	while (str[i] && str[i] != '\n')
	{
		ret[j] = str[i];
		i++;
		j++;
	}
	free(str);
	ret[j] = '\0';
	return (ret);
}
