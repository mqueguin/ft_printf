/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 15:23:33 by mqueguin          #+#    #+#             */
/*   Updated: 2021/02/01 15:42:28 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	}
	return (data);
}

int		ft_is_dot(char *str, int i, t_data data, va_list args)
{
	i++;
	if (str[i] == '*')
	{
		data.dot = va_arg(args, int);
		data.star = 1;
	}
	else
		while (ft_isdigit(str[i]))
			data.dot = (data.dot * 10) + ((int)str[i++] - 48);
	return (i);
}

t_data	ft_is_number(char c, t_data data)
{
	if (data.star == 1)
		data.width = 0;
	if (ft_isdigit(c))
		data.width = (data.width * 10) + (c - 48);
	return (data);
}
