/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-i <mlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 20:28:32 by tfiguero          #+#    #+#             */
/*   Updated: 2024/04/23 17:45:08 by mlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	calc_len(int nb)
{
	int	i;

	i = 0;
	if (nb <= 0)
		i++;
	while (nb != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*ret;
	size_t	i;

	i = calc_len(n);
	ret = ft_calloc(sizeof(char), i + 1);
	if (!ret)
		return (NULL);
	ret[i--] = '\0';
	if (n == 0)
	{
		ret[0] = '0';
		return (ret);
	}
	if (n < 0)
		ret[0] = '-';
	while (n != 0)
	{
		if (ret[0] == '-')
			ret[i] = '0' + -(n % 10);
		else
			ret[i] = '0' + (n % 10);
		n = n / 10;
		i--;
	}
	return (ret);
}
