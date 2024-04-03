/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero <tfiguero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 04:26:14 by tfiguero          #+#    #+#             */
/*   Updated: 2024/04/03 17:25:17 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(char *ehe, char *cmp)
{
	int	i;

	i = 0;
	if(!ehe || !cmp)
		return (1);
	while (ehe[i] && cmp[i])
	{
		if (ehe[i] != cmp[i])
			return (ehe[i] - cmp[i]);
		i++;
	}
	if ((ehe[i] && !cmp[i]) || (cmp[i] && !ehe[i]))
		return (ehe[i] - cmp[i]);
	return (0);
}
