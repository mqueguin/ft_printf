/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 15:48:29 by mqueguin          #+#    #+#             */
/*   Updated: 2021/02/01 15:52:54 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_treat_width(t_data data, int minus)
{
	while (data.width - minus > 0)
	{
		if (data.zero == 1)
			data.buffer[data.index++] = '0';
		else if (data.zero == 0)
			data.buffer[data.index++] = ' ';
		data.width--;
	}
}
