/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrazina <egrazina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 21:35:52 by egrazina          #+#    #+#             */
/*   Updated: 2020/11/08 23:31:26 by egrazina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERS_H
# define HEADERS_H

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

# define DICT_REF "numbers.dict"

int		ft_close_file(int fd);
int		ft_open_file(char *file);
void	ft_putstr(char *str);
char	*ft_strcat(char *dest, char *src);
char	*splitter(char *num);
char	*ft_strcpy(char *dest, const char *src);
int		ft_strlen(char *s);
char	*ft_reverse(char *str);
int		myatoi(char *str);
char	*ft_strstr(char *str, char *to_find);
char	*ft_getline(char *number);
void	parser(char *line);
int		countpoint(char *count_this);
char	*trimmer(char *to_trim);
void	transformer1(char *buffer);
void	transformer2(char *buffer);
void	writehundred(char *buffer);
void	writedez(char *buffer);
void	transformer3(char *buffer);
void	printer(char *buffer);
void	insertpoint(int point);
void	translator(char *ready);

#endif