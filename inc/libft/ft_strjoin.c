/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-i <mlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 01:43:43 by tfiguero          #+#    #+#             */
/*   Updated: 2024/05/06 19:48:47 by mlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	i;
	size_t	s1_len;
	size_t	s2_len;

	i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ret = (char *) malloc(s1_len + s2_len + 1);
	if (ret == NULL)
		return (NULL);
	while (i < s1_len && s1[i] != '\0')
	{
		ret[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < s2_len && s2[i] != '\0')
	{
		ret[s1_len + i] = s2[i];
		i++;
	}
	ret[s1_len + s2_len] = '\0';
	return (ret);
}

char	*ft_strjoinfree(char *s1, char *s2)
{
	char	*ret;
	size_t	i;
	size_t	s1_len;
	size_t	s2_len;

	i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ret = (char *) malloc(s1_len + s2_len + 1);
	if (ret == NULL)
		return (NULL);
	while (i < s1_len && s1[i] != '\0')
	{
		ret[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < s2_len && s2[i] != '\0')
	{
		ret[s1_len + i] = s2[i];
		i++;
	}
	ret[s1_len + s2_len] = '\0';
	free(s1);
	return (ret);
}

char	*ft_strjoin_char(char *str, char add)
{
	char	*new;
	int		i;

	i = 0;
	new = malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (!new)
		return (NULL);
	while (str && str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = add;
	new[i + 1] = '\0';
	free(str);
	return (new);
}
