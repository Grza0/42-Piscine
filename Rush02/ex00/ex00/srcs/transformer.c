/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrazina <egrazina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 23:18:32 by egrazina          #+#    #+#             */
/*   Updated: 2020/11/08 23:27:07 by egrazina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	transformer1(char *buffer)
{
	if (buffer[0] != '0')
		parser(ft_getline(buffer));
}

void	transformer2(char *buffer)
{
	char *temp;

	if (!(temp = malloc(3 * sizeof(char) + 1)))
		return ;
	temp[0] = buffer[0];
	temp[1] = buffer[1];
	if (temp[0] == '1')
	{
		parser(ft_getline(temp));
		ft_putstr(" ");
		free(temp);
		return ;
	}
	if (temp[0] != '1')
	{
		parser(ft_getline(ft_strcat(temp, "0")));
		parser(ft_getline(&temp[1]));
		ft_putstr(" ");
	}
	free(temp);
}

void	writehundred(char *buffer)
{
	char *temp;

	if (!(temp = malloc(3 * sizeof(char) + 1)))
		return ;
	temp[0] = buffer[0];
	parser(ft_getline(temp));
	ft_putstr(" ");
	parser(ft_getline("100"));
	ft_putstr(" ");
}

void	writedez(char *buffer)
{
	char *temp;

	if (!(temp = malloc(3 * sizeof(char) + 1)))
		return ;
	if (buffer[1] == '1')
	{
		temp[1] = buffer[1];
		temp[2] = buffer[2];
		parser(ft_getline(&temp[1]));
		ft_putstr(" ");
	}
	if (buffer[1] != '1' && buffer[1] != '0')
	{
		temp[1] = buffer[1];
		temp[2] = '0';
		parser(ft_getline(&temp[1]));
		if (buffer[2] != '0')
		{
			ft_putstr("-");
			temp[2] = buffer[2];
			parser(ft_getline(&temp[2]));
			ft_putstr(" ");
		}
	}
}

void	transformer3(char *buffer)
{
	char *temp;

	writehundred(buffer);
	writedez(buffer);
	if (!(temp = malloc(3 * sizeof(char) + 1)))
		return ;
	if (buffer[1] == '0')
		parser(ft_getline(&temp[2]));
}
