/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_div_set.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 23:19:16 by minskim           #+#    #+#             */
/*   Updated: 2020/06/15 20:42:38 by minskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_calculate_length_key_set(char *key)
{
	int i;

	i = 0;
	while (key[i])
		i++;
	return (i - 1);
}

int		*ft_calculate_div_set(char **key_set)
{
	int size;
	int *div_set;

	size = 0;
	while (key_set[size])
		size++;
	div_set = (int*)malloc(sizeof(int) * size);
	size = 0;
	while (key_set[size])
	{
		div_set[size] = ft_calculate_length_key_set(key_set[size]) / 3;
		size++;
	}
	return (div_set);
}
