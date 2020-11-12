/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrazina <egrazina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 16:43:27 by egrazina          #+#    #+#             */
/*   Updated: 2020/11/07 22:14:10 by egrazina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *ptr;
	int iterator;

	iterator = 0;
	if (min >= max)
		return (0);
	if (!(ptr = (int *)malloc(sizeof(int) * (max - min))))
		return (0);
	while (min < max)
	{
		*(ptr + iterator) = min;
		min++;
		iterator++;
	}
	return (ptr);
}
