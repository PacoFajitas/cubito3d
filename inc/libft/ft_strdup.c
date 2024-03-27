/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero <tfiguero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 23:12:47 by tfiguero          #+#    #+#             */
/*   Updated: 2023/05/12 04:48:47 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*ret;
	int		x;

	ret = (char *) malloc(ft_strlen(src) + 1);
	if (ret == NULL)
	{
		return (0);
	}
	x = 0;
	while (src[x] != '\0')
	{
		ret [x] = src[x];
		x++;
	}
	ret[x] = '\0';
	return (ret);
}
