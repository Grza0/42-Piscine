/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 10:11:29 by jibanez-          #+#    #+#             */
/*   Updated: 2020/10/28 10:11:33 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_alpha(char str)
{
	if ((str >= 'A' && str <= 'Z'))
		return (1);
	else if (str >= 'a' && str <= 'z')
		return (1);
	else
		return (0);
}

int		is_lower(char str)
{
	if ((str >= 'a' && str <= 'z'))
		return (1);
	else
		return (0);
}

int		is_upper(char str)
{
	if ((str >= 'A' && str <= 'Z'))
		return (1);
	else
		return (0);
}

int		is_numb(char str)
{
	if ((str >= '0' && str <= '9'))
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int flag;
	int i;

	flag = 1;
	i = 0;
	while (str[i] != '\0')
	{
		if (is_lower(str[i]) && flag)
		{
			str[i] = str[i] - ' ';
			flag = 0;
		}
		else if (is_upper(str[i]) && flag == 0)
			str[i] = str[i] + ' ';
		flag = 1;
		if (is_alpha(str[i]) || is_numb(str[i]))
			flag = 0;
		i++;
	}
	return (str);
}
