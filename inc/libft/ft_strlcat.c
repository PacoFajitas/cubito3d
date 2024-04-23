/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-i <mlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 21:06:37 by tfiguero          #+#    #+#             */
/*   Updated: 2024/04/23 17:45:21 by mlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

size_t	ft_strlcat(char	*dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	ret;
	size_t	dst_len;
	char	*s;

	s = (char *)src;
	i = 0;
	dst_len = ft_strlen((const char *)dst);
	if (dst_len > dstsize)
	{
		ret = ft_strlen((const char *)s) + dstsize;
	}
	else
	{
		ret = ft_strlen((const char *)s) + dst_len;
	}
	while (s[i] && dst_len + 1 < dstsize)
	{
		dst[dst_len] = s[i];
		i++;
		dst_len++;
	}
	dst[dst_len] = '\0';
	return (ret);
}
