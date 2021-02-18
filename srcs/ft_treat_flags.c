/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 15:23:33 by mqueguin          #+#    #+#             */
/*   Updated: 2021/02/18 11:58:28 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_data	ft_is_minus(t_data data)
{
	data.minus = 1;
	data.zero = 0;
	return (data);
}

t_data	ft_is_star(t_data data, va_list args)
{
	data.star = 1;
	data.width = va_arg(args, int);
	if (data.width < 0)
	{
		data.minus = 1;
		data.width *= -1;
		data.zero = 0;
	}
	return (data);
}

t_data	ft_is_dot(char *str, t_data *data, va_list args)
{
	data->b_dot = 1;
	data->i++;
	if (ft_check_type(str[data->i]))
		data->dot_exist = 0;
	if (str[data->i] == '*')
	{
		data->dot = va_arg(args, int);
		data->star = 1;
	}
	else
		while (ft_isdigit(str[data->i]))
			data->dot = (data->dot * 10) + ((int)str[data->i++] - 48);
	return (*data);
}

t_data	ft_is_number(char c, char d, t_data data)
{
	if (data.width != 0 && !ft_isdigit(d))
		data.width = 0;
	else
	{
		if (data.star == 1)
			data.width = 0;
		if (ft_isdigit(c))
			data.width = (data.width * 10) + (c - 48);
	}
	return (data);
}
