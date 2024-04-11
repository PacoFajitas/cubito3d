/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_tabs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-i <mlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 21:16:39 by mlopez-i          #+#    #+#             */
/*   Updated: 2024/04/11 20:40:11 by mlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_count_tabs(char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] == '\t')
			j++;
		i++;
	}
	return (j);
}

char	*ft_return_tabs_expanded(char *line, char *n_line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 9)
		{
			n_line = ft_strjoin_char(n_line, 32);
			n_line = ft_strjoin_char(n_line, 32);
			n_line = ft_strjoin_char(n_line, 32);
			n_line = ft_strjoin_char(n_line, 32);
		}
		else
			n_line = ft_strjoin_char(n_line, line[i]);
		i++;
	}
	free(line);
	return (n_line);
}

char	*ft_expand_tabs(char *line)
{
	int		i;
	int		k;
	char	*new_line;

	if (!line)
		return (NULL);
	i = ft_strlen(line);
	k = ft_count_tabs(line);
	new_line = ft_calloc(i + (k * 4 - k), sizeof(char));
	if (!new_line)
	{
		perror("malloc");
		exit(1);
	}
	return (ft_return_tabs_expanded(line, new_line));
}
