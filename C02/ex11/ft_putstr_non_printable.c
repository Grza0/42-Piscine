/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrazina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 13:02:46 by egrazina          #+#    #+#             */
/*   Updated: 2020/10/29 21:40:37 by egrazina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_hex(char c)
{
	c = c + '0';
	if (c > '9')
		c = c + 39;
	write(1, &c, 1);
}

void	convert_to_hex(char hex)
{
	write(1, "\\", 1);
	print_hex((int)hex / 16);
	print_hex((int)hex % 16);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str != '\0')
	{
		if (*str <= 31 || *str >= 127)
			convert_to_hex(*str);
		else
			write(1, str, 1);
		str++;
	}
}
