/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrazina <egrazina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 23:19:15 by egrazina          #+#    #+#             */
/*   Updated: 2020/11/08 23:19:25 by egrazina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	printer(char *buffer)
{
	int		k;
	int		len;
	char	*temp;
	char	*thousand;

	thousand = "1000";
	k = 0;
	buffer = trimmer(buffer);
	len = ft_strlen(buffer);
	if (!(temp = malloc(3 * sizeof(char) + 1)))
		return ;
	if (len == 3)
	{
		transformer3(buffer);
	}
	if (len == 2)
	{
		transformer2(buffer);
	}
	if (len == 1)
	{
		transformer1(buffer);
	}
}

void	insertpoint(int point)
{
	char *thousand;

	if (!(thousand = (char *)malloc(1024)))
		return ;
	thousand = ft_strcpy(thousand, "1000");
	while (point > 1)
	{
		thousand = ft_strcat(thousand, "000");
		point--;
	}
	if (point == 1)
	{
		parser(ft_getline(thousand));
	}
}

void	translator(char *ready)
{
	int		k;
	int		x;
	int		point;
	char	*buffer;

	k = ft_strlen(ready) - 1;
	point = countpoint(ready);
	if (!(buffer = malloc(3 * sizeof(char) + 1)))
		return ;
	while (k >= 0)
	{
		x = 0;
		while (ready[k] != '.')
		{
			buffer[x] = ready[k];
			k--;
			x++;
		}
		printer(buffer);
		insertpoint(point);
		ft_putstr(" ");
		point--;
		k--;
	}
	free(buffer);
}
