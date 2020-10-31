/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrazina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 21:48:07 by egrazina          #+#    #+#             */
/*   Updated: 2020/10/29 21:48:09 by egrazina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_strcmp(char *s1, char *s2)
{
	unsigned char i;
	
	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	return(s1[i] - s2[i]);
}

int main()
{
	char *st = "olaaaaaa";
	char *st1 = "olas";
	printf("%d", ft_strcmp(st, st1));

	return (0);
}