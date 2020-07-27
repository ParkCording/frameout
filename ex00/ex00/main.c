/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 00:11:44 by minskim           #+#    #+#             */
/*   Updated: 2020/06/17 13:36:29 by minskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"
#include <stdio.h>

void	ft_print_error(void)
{
	char	*error;
	char	c;
	int		i;

	error = "Error";
	i = 0;
	while (error[i])
	{
		c = error[i];
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int		ft_input_str_is_ok(char *input_str)
{
	int i;

	i = 0;
	while (input_str[i])
	{
		if (!(input_str[i] >= '0' && input_str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	char *input_str;

	if (argc == 1 || argc > 3)
	{
		ft_print_error();
		return (0);
	}
	if (argc == 2)
		input_str = argv[1];
	else
		input_str = argv[2];
	if (!ft_input_str_is_ok(input_str))
	{
		ft_print_error();
		return (0);
	}
	ft_dict_parsing(input_str, 0);
	return (0);
}
