/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrazina <egrazina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 09:05:13 by egrazina          #+#    #+#             */
/*   Updated: 2020/11/11 23:40:37 by egrazina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		is_in_charset(char c, char *charset)
{
	int i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int		word_count(char *str, char *charset)
{
	int count;
	int i;

	count = 0;
	while (str[i])
	{
		if (!is_in_charset(str[i], charset))
		{
			i++;
			while (str[i] != '\0' && !is_in_charset(str[i], charset))
				i++;
		}
		i++;
	}
	return (count);
}

void	ft_strcpy(char *dest, char *from, char *str)
{
	while (from < str)
		*(dest++) = *(from++);
	*dest = 0;
}

char	**ft_split(char *str, char *charset)
{
	char	**ret;
	int		index;
	char	*from;
	int		i;

	if (!(ret = malloc(sizeof(char*) * word_count(str, charset) + 1)))
		return (0);
	index = 0;
	i = 0;
	while (str[i])
	{
		if (!is_in_charset(str[i], charset))
		{
			from = str;
			while (str[i] && !is_in_charset(str[i], charset))
				i++;
			ret[index] = (char*)malloc(str - from + 1);
			ft_strcpy(ret[index++], from, str);
		}
		i++;
	}
	ret[index] = 0;
	return (ret);
}

int main()
{
	char **huhu;
	huhu = ft_split("coucouPjePRsuisOUTunPTpetitRUOTPblagueur.", "PROUT");
	int i = 0;
	while (i < 7)
	{
		printf("%s ", huhu[i++]);
	}
}