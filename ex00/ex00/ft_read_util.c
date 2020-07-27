/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 21:05:57 by minskim           #+#    #+#             */
/*   Updated: 2020/06/15 21:55:21 by minskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int		ft_is_can_solve(int change_index, int *d_set, char **k_set)
{
	int div;
	int size;
	int i;

	div = change_index / 3;
	size = 0;
	while (k_set[size])
		size++;
	i = 0;
	while (i < size)
	{
		if (d_set[i] == div)
			return (1);
		i++;
	}
	ft_dict_error();
	return (0);
}

void	ft_find_v_set_at_hundred(char *tmp, char **k_set, char **v_set)
{
	int k_set_index;

	k_set_index = 0;
	while (1)
	{
		if (!(ft_strcmp(tmp, k_set[k_set_index])))
		{
			ft_print_value(v_set[k_set_index]);
			ft_putchar(' ');
			ft_hundred();
			g_unit_flag = 1;
			break ;
		}
		k_set_index++;
	}
}

void	ft_find_v_set_at_ten(char *tmp, char **k_set, char **v_set)
{
	int k_set_index;

	k_set_index = 0;
	while (1)
	{
		if (!(ft_strcmp(tmp, k_set[k_set_index])))
		{
			ft_print_value(v_set[k_set_index]);
			g_unit_flag = 1;
			break ;
		}
		k_set_index++;
	}
}

void	ft_find_v_set_one(char *tmp, char **k_set, char **v_set)
{
	int k_set_index;

	k_set_index = 0;
	while (1)
	{
		if (!(ft_strcmp(tmp, k_set[k_set_index])))
		{
			ft_print_value(v_set[k_set_index]);
			break ;
		}
		k_set_index++;
	}
}

void	ft_find_v_set_two(int index, int *d_set, char **v_set)
{
	int k_set_index;

	k_set_index = 0;
	while (1)
	{
		if (index / 3 == d_set[k_set_index])
		{
			ft_putchar(' ');
			ft_print_value(v_set[k_set_index]);
			break ;
		}
		k_set_index++;
	}
}
