/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero <tfiguero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:57:53 by tfiguero          #+#    #+#             */
/*   Updated: 2024/04/10 19:14:35 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str, const char *cmp, size_t n)
{
	size_t	x;

	x = 0;
	if(!str)
		return (-1);
	if(!cmp)
		return (1);
	if (n == 0)
		return (0);
	while (x < n && ((unsigned char *)str)[x] == ((unsigned char *)cmp)[x]
	&& str[x] && cmp[x])
		x++;
	if (x == n)
		x--;
	return ((unsigned char)str[x] - (unsigned char)cmp[x]);
}
