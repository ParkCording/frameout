/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 20:42:51 by minskim           #+#    #+#             */
/*   Updated: 2020/06/15 21:08:49 by minskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_hundred(void)
{
	char	*hundred;
	int		i;

	hundred = "hundred";
	i = 0;
	while (hundred[i])
	{
		ft_putchar(hundred[i]);
		i++;
	}
}

void	ft_dict_error(void)
{
	char	*dict_error;
	int		i;

	dict_error = "Dict Error";
	i = 0;
	while (dict_error[i])
	{
		ft_putchar(dict_error[i]);
		i++;
	}
}

void	ft_print_value(char *value)
{
	int i;

	i = 0;
	while (value[i])
	{
		ft_putchar(value[i]);
		i++;
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (1)
	{
		i = *s1 - *s2;
		if (*s1 != *s2 || *s1 == '\0' || *s2 == '\0')
		{
			return (i);
		}
		s1++;
		s2++;
	}
}
