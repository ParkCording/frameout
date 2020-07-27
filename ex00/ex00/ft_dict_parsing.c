/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 18:04:31 by minskim           #+#    #+#             */
/*   Updated: 2020/06/17 13:36:39 by minskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"
#include <stdio.h>

void	ft_make_array(char *buf, char **k_set, char **v_set, int new_line_num)
{
	int i;
	int index;

	i = 0;
	index = 0;
	while (buf[i])
	{
		if (buf[i] >= '0' && buf[i] <= '9')
			k_set[new_line_num][index++] = buf[i];
		else if (buf[i] == ':')
		{
			k_set[new_line_num][index] = '\0';
			index = 0;
		}
		else if (buf[i] >= 'a' && buf[i] <= 'z')
			v_set[new_line_num][index++] = buf[i];
		else if (buf[i] == '\n')
		{
			v_set[new_line_num][index] = '\0';
			new_line_num++;
			index = 0;
		}
		i++;
	}
}

int		ft_check_dict_size(int fd, char *buf)
{
	int new_line_num;
	int i;

	new_line_num = 0;
	i = 0;
	while (read(fd, &buf[i], 1))
	{
		if (buf[i] == '\n')
			new_line_num++;
		i++;
	}
	buf[i] = '\0';
	return (new_line_num + 1);
}

char	**ft_make_value_set(char *buf, int size)
{
	char	**value_set;
	int		i;
	int		length;
	int		index;

	length = 0;
	index = 0;
	i = 0;
	value_set = (char**)malloc(sizeof(char*) * size);
	while (buf[i])
	{
		if (buf[i] >= 'a' && buf[i] <= 'z')
			length++;
		else if (buf[i] == '\n')
		{
			value_set[index] = (char*)malloc(sizeof(char) * (length + 1));
			index++;
			length = 0;
		}
		i++;
	}
	value_set[index] = NULL;
	return (value_set);
}

char	**ft_make_key_set(char *buf, int size)
{
	char	**key_set;
	int		i;
	int		length;
	int		index;

	length = 0;
	index = 0;
	i = 0;
	key_set = (char**)malloc(sizeof(char*) * size);
	while (buf[i])
	{
		if (buf[i] >= '0' && buf[i] <= '9')
			length++;
		else if (buf[i] == '\n')
		{
			key_set[index] = (char*)malloc(sizeof(char) * (length + 1));
			index++;
			length = 0;
		}
		i++;
	}
	key_set[index] = NULL;
	return (key_set);
}

void	ft_dict_parsing(char *input_str, int fd)
{
	char	buf[1024];
	char	**key_set;
	char	**value_set;
	int		*div_set;
	int		size;

	fd = open("numbers.dict", O_RDONLY);
	if (fd == -1)
		return ;
	size = ft_check_dict_size(fd, buf);
	close(fd);
	key_set = ft_make_key_set(buf, size);
	value_set = ft_make_value_set(buf, size);
	ft_make_array(buf, key_set, value_set, 0);
	div_set = ft_calculate_div_set(key_set);
	ft_read(input_str, key_set, value_set, div_set);
	free(key_set);
	free(value_set);
	free(div_set);
}
