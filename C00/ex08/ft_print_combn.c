/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrazina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 12:36:00 by egrazina          #+#    #+#             */
/*   Updated: 2020/10/25 12:36:03 by egrazina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	g_flag;
char g_array[10];

void	ft_start(void)
{
	int asize;

	asize = 0;
	while (asize < 10)
	{
		g_array[asize] = '\0';
		asize++;
	}
}

void	ft_recursive(int i, int l, int n)
{
	if (i == n)
	{
		if (g_flag)
			write(1, ", ", 2);
		write(1, &g_array, n);
		g_flag = 1;
		return ;
	}
	else if (l == 9 && i < n)
		return ;
	while (++l < 10)
	{
		g_array[i] = '0' + l;
		ft_recursive(i + 1, l, n);
	}
}

void	ft_print_combn(int n)
{
	if (n == 0)
		return ;
	ft_start();
	ft_recursive(0, -1, n);
}
