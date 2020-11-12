/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrazina <egrazina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 15:35:31 by egrazina          #+#    #+#             */
/*   Updated: 2020/11/12 15:36:06 by egrazina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int		ft_open_file(char *file)
{
	return (open(file, O_RDONLY));
}

int		ft_close_file(int fd)
{
	return (close(fd));
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;

	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_strcpy(char *dest, const char *src)
{
	unsigned int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (dest);
}

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char 	*ft_reverse(char *str)
{
	char 	*revStr = malloc(100 * sizeof(char) + 1);
	int 	i;
	int		j;
	int 	len;

	i = 0;
  	j = 0;
  	len = ft_strlen(str);
	i = len - 1;
	while(i >= 0)
	{
  		revStr[j++] = str[i];
		i--;
  	}
  	revStr[i] = '\0';
  	return revStr;
}

int myAtoi(char* str)
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
	return res;
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
					while(str[i + j])
						(str[i + j] == '\n') ? str[i + j] = '\0' : j++;
					return (&str[i]);
				}
			j++;
			}
		}
		i++;
	}
	printf("\n%s\n", to_find);
	return 0;
}

char	*ft_getline(char *number)
{
	char total[100000];
	int a;
	int i;

	i = 0;
	a = 1;
	char buffer[1];
	int fd = ft_open_file("numbers.dict");
	while(a > 0)
	{
		a = read(fd, buffer , sizeof(buffer));
		if(a)
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
	while((line[i] >= 32 && line[i] <= 126) && line[i] != ':')
		i--;
	while(line[i] == 32 || line[i] == ':')
		i++;
	write(1, &line[i],ft_strlen(line) - i );
}

char * splitter(char *num)
{
	int i;
	int size;
	size = ft_strlen(num);
	int k;
	
	i = 0;
	k = 0;
	char *split = (char *)malloc((size + (size / 3)) * sizeof(char) + 1);
	while(num[--size])
	{
		if(i == 3)
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
	return split;
}

int		countpoint(char *count_this)
{
	int point;
	int i;

	i = 0;
	point = 0;
	while(count_this[i])
	{
		if(count_this[i] == '.')
			point++;
	i++;
	}
	return point;
}

char	*trimmer(char *to_trim)
{
	int size;
	int i;
	int j;
	int found_number;

	found_number = 0;
	size = ft_strlen(to_trim) - 1;
	i = 0;
	j = 0;	
	while(to_trim[i] == '0' && found_number == 0)
	{
		if(to_trim[i] != '0')
			found_number = 1;
		i++;
	}
	char *new = malloc((size - i) * sizeof(char) + 1);
	while(to_trim[i])
	{
		new[j] = to_trim[i];
		j++;
		i++;
	}
	return (new);
}

void	transformer1(char *buffer)
{
	if(buffer[0] != '0')
		parser(ft_getline(buffer));
}

void	transformer2(char *buffer)
{
	char *temp = malloc(3 *sizeof(char) + 1);
	temp[0] = buffer[0];
	temp[1] = buffer[1];
	if(temp[0] == '1')
	{
		parser(ft_getline(temp));
		ft_putstr(" ");
		free(temp);
		return;
	}
	if(temp[0] != '1')
	{
		parser(ft_getline(ft_strcat(temp, "0")));
		parser(ft_getline(&temp[1]));
		ft_putstr(" ");
	}
	free(temp);
}

void	writeHundred(char *buffer)
{
	char *temp = malloc(3 *sizeof(char) + 1);
	temp[0] = buffer[0];
	parser(ft_getline(temp));
	ft_putstr(" " );
	parser(ft_getline("100"));
	ft_putstr(" ");
}

void	writeDez(char *buffer)
{
	char *temp = malloc(3 * sizeof(char) + 1);
	if(buffer[1] == '1')
	{
		temp[1] = buffer[1];
		temp[2] = buffer[2];
		parser(ft_getline(&temp[1]));
		ft_putstr(" ");
	}
	if(buffer[1] != '1' && buffer[1] != '0')
	{
		temp[1] = buffer[1];
		temp[2] = '0';
		parser(ft_getline(&temp[1]));
		if(buffer[2] != '0')
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
	char *temp = malloc(3 * sizeof(char) + 1);
	writeHundred(buffer);
	writeDez(buffer);
	if(buffer[1] == '0')
		parser(ft_getline(&temp[2]));
}

void printer(char *buffer)
{
	int k;
	int len;
	int converted;
	char *temp = malloc(3 *sizeof(char) + 1);
	char *thousand = "1000";
	int point;

	k = 0;
	buffer = trimmer(buffer);
	len = ft_strlen(buffer);
	if(len == 3)
	{
		transformer3(buffer);
	}
	if(len == 2)
	{
		transformer2(buffer);
	}
	if(len == 1)
	{
		transformer1(buffer);
	}
}

void	insertpoint(int	point)
{
	char *thousand  = (char *)malloc(1024);
	thousand = ft_strcpy(thousand,"1000");
	while(point > 1)
	{
		thousand = ft_strcat(thousand, "000");
		point--;
	}
	if(point == 1)
	{
		parser(ft_getline(thousand));
	}
}

void	translator(char *ready)
{
	int k;
	int point;
	int x;
	char *buffer = malloc(3 * sizeof(char) + 1);
	point = countpoint(ready);
	k = ft_strlen(ready) - 1;
	while(k >= 0)
	{
		x = 0;
		while(ready[k] != '.')
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

int main(int argc, char **argv)
{
	char *new = splitter(trimmer(argv[1]));
	translator(new);

}
