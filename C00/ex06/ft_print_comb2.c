/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrazina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 13:46:42 by egrazina          #+#    #+#             */
/*   Updated: 2020/10/24 19:51:43 by egrazina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_print_dobdigit(int a, int b, int flag)
{
	if (flag)
		write(1, ", ", 2);
	ft_putchar(a / 10 + '0');
	ft_putchar(a % 10 + '0');
	ft_putchar(' ');
	ft_putchar(b / 10 + '0');
	ft_putchar(b % 10 + '0');
	return (1);
}

void	ft_print_comb2(void)
{
	int a;
	int b;
	int flag;

	flag = 0;
	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			flag = ft_print_dobdigit(a, b, flag);
			b++;
		}
		a++;
	}
}

int 	main(void)
{
	ft_print_comb2();
	return(0);
}
