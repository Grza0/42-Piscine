/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrazina <egrazina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 22:23:04 by egrazina          #+#    #+#             */
/*   Updated: 2020/11/08 23:26:48 by egrazina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int		ft_open_file(char *file)
{
	return (open(file, O_RDONLY));
}

int		ft_close_file(int fd)
{
	return (close(fd));
}

int		main(int argc, char **argv)
{
	char *new;
	if (argc >= 2)
		return (0);
	new = splitter(trimmer(argv[1]));
	translator(new);
	return (0);
}
