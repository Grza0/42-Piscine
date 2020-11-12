/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrazina <egrazina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 23:16:21 by egrazina          #+#    #+#             */
/*   Updated: 2020/11/08 23:16:22 by egrazina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int		myatoi(char *str)
{
	int res;
	int i;

	i = 0;
	res = 0;
	while (str[i] != '\0')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res);
}

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;

	if (to_find[0] == '\0')
		return (str);
	i = 0;
	while (str[i])
	{
		j = 0;
		if (str[i] == to_find[j])
		{
			while (str[i + j] == to_find[j])
			{
				if (to_find[j + 1] == '\0')
				{
					while (str[i + j])
						(str[i + j] == '\n') ? str[i + j] = '\0' : j++;
					return (&str[i]);
				}
				j++;
			}
		}
		i++;
	}
	return (0);
}
