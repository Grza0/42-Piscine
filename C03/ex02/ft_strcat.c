/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrazina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 21:20:02 by egrazina          #+#    #+#             */
/*   Updated: 2020/11/01 21:20:03 by egrazina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (dest[i])
		i++;
	while (src[n])
	{
		dest[i] = src[n];
		n++;
	}
	dest[i] = '\0';

	return (dest);
}

int main()
{
	char src[7] = "DASDADA";
	char dest[4] = "sdas";

	printf("%s", ft_strcat(dest, src));

	return (0);
}