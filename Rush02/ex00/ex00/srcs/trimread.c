/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trimread.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrazina <egrazina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 23:17:34 by egrazina          #+#    #+#             */
/*   Updated: 2020/11/08 23:32:34 by egrazina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

char	*ft_getline(char *number)
{
	char	total[100000];
	int		a;
	int		i;
	int		fd;
	char	buffer[1];

	i = 0;
	a = 1;
	fd = ft_open_file("numbers.dict");
	while (a > 0)
	{
		a = read(fd, buffer, sizeof(buffer));
		if (a)
		{
			total[i] = buffer[0];
		}
		i++;
	}
	total[i] = '\0';
	return (ft_strstr(total, number));
}

void	parser(char *line)
{
	int i;

	i = ft_strlen(line) - 1;
	while ((line[i] >= 32 && line[i] <= 126) && line[i] != ':')
		i--;
	while (line[i] == 32 || line[i] == ':')
		i++;
	write(1, &line[i], ft_strlen(line) - i);
}

char	*splitter(char *num)
{
	int		i;
	int		size;
	int		k;
	char	*split;

	i = 0;
	k = 0;
	size = ft_strlen(num);
	if (!(split = (char *)malloc((size + (size / 3)) * sizeof(char) + 1)))
		return ("Error");
	while (num[--size])
	{
		if (i == 3)
		{
			split[k] = '.';
			i = 0;
			k++;
		}
		split[k] = num[size];
		k++;
		i++;
	}
	split[size] = '\0';
	return (split);
}

int		countpoint(char *count_this)
{
	int point;
	int i;

	i = 0;
	point = 0;
	while (count_this[i])
	{
		if (count_this[i] == '.')
			point++;
		i++;
	}
	return (point);
}

char	*trimmer(char *to_trim)
{
	int size;
	int i;
	int j;
	int found_number;
	char*new;

	found_number = 0;
	size = ft_strlen(to_trim) - 1;
	i = 0;
	j = 0;
	while (to_trim[i] == '0' && found_number == 0)
	{
		if (to_trim[i] != '0')
			found_number = 1;
		i++;
	}
	if (!(new = malloc((size - i) * sizeof(char) + 1)))
		return (0);
	while (to_trim[i])
	{
		new[j] = to_trim[i];
		j++;
		i++;
	}
	return (new);
}
