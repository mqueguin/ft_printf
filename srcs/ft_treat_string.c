/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 11:41:47 by mqueguin          #+#    #+#             */
/*   Updated: 2021/02/11 14:29:21 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_treat_string(char *str, t_data *data)
{
	char	*space;
	
	if (!str)
		str = "(null)";
	if (data->b_dot == 1 && data->dot == 0)
	{
		space = ft_treat_width(data);
		ft_add_to_buffer(data, space, data->len_space);
		return ;
	}
	data->len_variable = (int)ft_strlen(str);
	if (data->dot > 0 && data->dot > data->len_variable)
		data->dot = data->len_variable;
	space = ft_treat_width(data);
	if (data->minus == 1)
	{
		if (data->dot > 0)
			ft_add_to_buffer(data, str, data->dot);
		else
			ft_add_to_buffer(data, str, data->len_variable);
	}
	ft_add_to_buffer(data, space, data->len_space);
	if (data->minus == 0)
	{
		if (data->dot > 0)
			ft_add_to_buffer(data, str, data->dot);
		else
		{
			ft_add_to_buffer(data, str, data->len_variable);
		}
	}
	free(space);
}
