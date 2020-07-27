/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 11:49:10 by minskim           #+#    #+#             */
/*   Updated: 2020/06/14 23:14:51 by minskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	mod_zero_first(char *input_str, int *d_set, char **v_set, char **k_set)
{
	char *tmp;

	tmp = (char*)malloc(sizeof(char) * 3);
	tmp[0] = '1';
	tmp[1] = input_str[g_read_index];
	tmp[2] = '\0';
	ft_find_v_set_one(tmp, k_set, v_set);
	if ((g_index / 3 > 0) && g_unit_flag == 1)
		ft_find_v_set_two(g_index, d_set, v_set);
	g_read_teen = 0;
}

void	mod_zero_second(char *input_str, int *d_set, char **v_set, char **k_set)
{
	char *tmp;

	tmp = (char *)malloc(sizeof(char) * 2);
	tmp[0] = input_str[g_read_index];
	tmp[1] = '\0';
	ft_find_v_set_one(tmp, k_set, v_set);
	if (g_index / 3 > 0)
		ft_find_v_set_two(g_index, d_set, v_set);
	free(tmp);
}

void	ft_mod(char *input_str, char **k_set, char **v_set, int *d_set)
{
	if (g_index % 3 == 2)
		mod_two(input_str, k_set, v_set);
	else if (g_index % 3 == 1)
		mod_one(input_str, k_set, v_set);
	else if (g_index % 3 == 0)
	{
		if (g_read_teen == 1)
			mod_zero_first(input_str, d_set, v_set, k_set);
		else if (input_str[g_read_index] == '0')
		{
			if ((g_index / 3 > 0) && g_unit_flag == 1)
				ft_find_v_set_two(g_index, d_set, v_set);
		}
		else
			mod_zero_second(input_str, d_set, v_set, k_set);
		g_unit_flag = 0;
	}
}

int		ft_input_str_is_zero(char *input_str)
{
	char	*zero;
	char	*txt_zero;
	int		i;

	zero = "0";
	txt_zero = "zero";
	i = 0;
	if (!ft_strcmp(zero, input_str))
	{
		while (txt_zero[i])
		{
			ft_putchar(txt_zero[i]);
			i++;
		}
		ft_putchar('\n');
		return (1);
	}
	return (0);
}

void	ft_read(char *input_str, char **k_set, char **v_set, int *d_set)
{
	int		input_length;

	g_read_teen = 0;
	input_length = ft_input_length(input_str);
	g_read_index = 0;
	g_unit_flag = 1;
	if (ft_input_str_is_zero(input_str))
		return ;
	while (input_str[g_read_index])
	{
		g_index = input_length - g_read_index;
		if (!ft_is_can_solve(g_index, d_set, k_set))
			break ;
		if (g_read_index != 0)
			if (!((g_index % 3 == 1) && (input_str[g_read_index] == '1')))
				ft_putchar(' ');
		ft_mod(input_str, k_set, v_set, d_set);
		g_read_index++;
	}
	ft_putchar('\n');
}
