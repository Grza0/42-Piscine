/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrazina <egrazina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:21:35 by egrazina          #+#    #+#             */
/*   Updated: 2020/11/07 20:05:04 by egrazina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		length_strs;
	int		i;
	char	*cat;
	char	*tmp;

	if (!size)
	{
		cat = ((char *)malloc(1));
		cat[0] = 0;
		return (cat);
	}
	length_strs = 0;
	i = 0;
	while (i < size)
		length_strs += ft_strlen(strs[i++]);
	cat = (char *)malloc(length_strs + (size - 1) * ft_strlen(sep) + 1);
	tmp = ft_strcat(cat, strs[0]);
	i = 1;
	while (i < size)
	{
		tmp = ft_strcat(tmp, sep);
		tmp = ft_strcat(tmp, strs[i++]);
	}
	*tmp = 0;
	return (cat);
}
