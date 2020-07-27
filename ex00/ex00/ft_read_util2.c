/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_util2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 22:27:08 by minskim           #+#    #+#             */
/*   Updated: 2020/06/16 00:36:52 by minskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int		ft_input_length(char *input_str)
{
	int i;

	i = 0;
	while (input_str[i])
		i++;
	i--;
	return (i);
}

void	mod_two(char *input_str, char **k_set, char **v_set)
{
	char *tmp;

	if (input_str[g_read_index] != '0')
	{
		tmp = (char*)malloc(sizeof(char) * 2);
		tmp[0] = input_str[g_read_index];
		tmp[1] = '\0';
		ft_find_v_set_at_hundred(tmp, k_set, v_set);
		free(tmp);
	}
}

void	mod_one(char *input_str, char **k_set, char **v_set)
{
	char *tmp;

	if (input_str[g_read_index] == '1')
	{
		g_read_teen = 1;
		g_unit_flag = 1;
	}
	else if (input_str[g_read_index] >= '2' && input_str[g_read_index] <= '9')
	{
		tmp = (char *)malloc(sizeof(char) * 3);
		tmp[0] = input_str[g_read_index];
		tmp[1] = '0';
		tmp[2] = '\0';
		ft_find_v_set_at_ten(tmp, k_set, v_set);
		free(tmp);
	}
}
