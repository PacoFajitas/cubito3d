/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-i <mlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:56:52 by tfiguero          #+#    #+#             */
/*   Updated: 2024/04/23 17:45:31 by mlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

char	*ft_strrchr(const char *str, int c)
{
	int	x;
	int	i;

	i = -1;
	x = 0;
	while (str[x] != '\0')
	{
		if (str[x] == (unsigned char)c)
			i = x;
		x++;
	}
	if (i != -1)
	{
		return (&((char *)str)[i]);
	}
	if ((unsigned char)c == '\0')
	{
		return ((char *)(str + x));
	}
	return (NULL);
}
