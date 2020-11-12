/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrazina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 03:49:54 by egrazina          #+#    #+#             */
/*   Updated: 2020/11/04 04:06:42 by egrazina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_iterative_power(int nb, int power)
{
	int nbr;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	nbr = nb;
	while (--power)
		nbr *= nb;
	return (nbr);
}
