/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrazina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:41:46 by egrazina          #+#    #+#             */
/*   Updated: 2020/11/04 02:02:06 by egrazina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		checkbase(char *base)
{
	int	i;

	if (*base == 0 || *(base + 1) == 0)
		return (0);
	while (*base)
	{
		if (*base == '+' || *base == '-' || *base <= 32)
			return (0);
		i = 1;
		while (*(base + i))
		{
			if (*(base + i) == *base)
				return (0);
			i++;
		}
		base++;
	}
	return (1);
}

int		ft_strlen(char *base)
{
	int i;

	i = 0;
	while (base[i] != '\0')
		i++;
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int nb;
	unsigned int basel;

	basel = ft_strlen(base);
	if (checkbase(base))
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			nb = nbr * -1;
		}
		else
			nb = nbr;
		if (nb >= basel)
		{
			ft_putnbr_base(nb / basel, base);
			ft_putnbr_base(nb % basel, base);
		}
		else
			write(1, base + nb, 1);
	}
}
