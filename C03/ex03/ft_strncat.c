/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrazina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 22:38:01 by egrazina          #+#    #+#             */
/*   Updated: 2020/11/01 22:38:03 by egrazina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int i;
	unsigned int h;

	i = 0;
	h = 0;
	while (dest[i] != '\0')
		i++;
	while (src[h] && h < nb)
	{
		dest[i] = src[h];
		h++;
	}
	dest[i] = '\0';
	return (dest);
}

int main()
{
	char src[7] = "sdadsad";
	char dest[3] = "ola";

	printf("%s", ft_strncat(dest, src, 2));
	
	return (0);
}
