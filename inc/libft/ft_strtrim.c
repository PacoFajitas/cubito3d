/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-i <mlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 03:05:07 by tfiguero          #+#    #+#             */
/*   Updated: 2024/05/06 20:01:28 by mlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char *s1, char const *set)
{
	size_t	fin;
	char	*ret;

	if (s1 == NULL || set == NULL)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	fin = ft_strlen(s1);
	while (fin && ft_strchr(set, s1[fin]))
		fin--;
	ret = ft_substr(s1, 0, fin + 1);
	free(s1);
	return (ret);
}
