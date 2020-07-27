/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 20:33:55 by minskim           #+#    #+#             */
/*   Updated: 2020/06/29 22:39:30 by minskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

int		g_unit_flag;
int		g_read_teen;
int		g_read_index;
int		g_index;

void	ft_make_array(char *buf, char **k_set, char **v_set, int new_line_num);
int		ft_check_dict_size(int fd, char *buf);
char	**ft_make_value_set(char *buf, int size);
char	**ft_make_key_set(char *buf, int size);
void	ft_dict_parsing(char *input_str, int fd);
int		ft_input_str_is_ok(char *input_str);
void	ft_print_error(void);
int		ft_calculate_length_key_set(char *key);
int		*ft_calculate_div_set(char **key_set);
void	ft_putchar(char c);
void	ft_hundred(void);
void	ft_dict_error(void);
void	ft_print_value(char *value);
int		ft_strcmp(char *s1, char *s2);
int		ft_is_can_solve(int change_index, int *d_set, char **k_set);
void	ft_read(char *input_str, char **k_set, char **v_set, int *d_set);
void	ft_find_v_set_at_hundred(char *tmp, char **k_set, char **v_set);
void	ft_find_v_set_at_ten(char *tmp, char **k_set, char **v_set);
void	ft_find_v_set_one(char *tmp, char **k_set, char **v_set);
void	ft_find_v_set_two(int index, int *d_set, char **v_set);
int		ft_input_length(char *input_str);
void	mod_two(char *input_str, char **k_set, char **v_set);
void	mod_one(char *input_str, char **k_set, char **v_set);
void	mod_zero_first(char *input_str, int *d_set, char **v_set, char **k_set);
void	mod_zero_second(char *input_str, int *d_set,
						char **v_set, char **k_set);
void	ft_mod(char *input_str, char **k_set, char **v_set, int *d_set);
int		ft_input_str_is_zero(char *input_str);

#endif
