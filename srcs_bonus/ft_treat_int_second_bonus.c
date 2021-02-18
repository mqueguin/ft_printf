/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_int_second_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 10:16:15 by mqueguin          #+#    #+#             */
/*   Updated: 2021/02/18 10:29:58 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/ft_printf_bonus.h"

void	ft_treat_special_cases_int(int nbr, t_data *data, char *str)
{
	if (nbr == 0 && data->b_dot == 1 && data->dot == 0
			&& data->dot_exist == 0 && data->plus == 0)
		data->len_variable = 0;
	else if (nbr >= 0 && data->space == 1 && data->b_dot == 0
			&& data->width == 0)
	{
		data->len_variable = (int)ft_strlen(str);
		data->width = ((int)ft_strlen(str) + 1);
	}
	else if (nbr >= 0 && data->plus == 1)
	{
		if ((nbr == 0 && data->dot == 0 && data->dot_exist == 1
					&& data->b_dot == 1) || (nbr == 0 && data->dot == 0
						&& data->b_dot == 1 && data->dot_exist == 0))
			data->len_variable = 1;
		else
			data->len_variable = (int)ft_strlen(str) + 1;
	}
	else if (nbr < 0 || (nbr >= 0 && data->plus == 1))
		data->len_variable = (int)ft_strlen(str) + 1;
}

void	ft_treat_int_second(int nbr, t_data *data, char *space)
{
	if ((data->zero == 0) || (data->zero == 1 && nbr >= 0 && data->plus == 0))
	{
		if (data->minus == 1 && data->space == 1 && nbr >= 0)
			ft_add_to_buffer(data, space, data->len_space
					- (data->len_fill + 1));
		else if (data->minus == 0 && data->space == 1 && nbr >= 0)
		{
			ft_add_to_buffer(data, " ", 1);
			ft_add_to_buffer(data, space, data->len_space
					- (data->len_fill + 1));
		}
		else
			ft_add_to_buffer(data, space, data->len_space - data->len_fill);
	}
}
