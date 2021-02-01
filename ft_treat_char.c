/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 15:42:35 by mqueguin          #+#    #+#             */
/*   Updated: 2021/02/01 15:51:36 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_treat_char(int c, t_data data)
{
	if (data.minus == 1)
		data.buffer[data.index++] = c;
	ft_treat_width(data, 1);
	if (data.minus == 0)
		data.buffer[data.index++] = c;
	data.buffer[data.index++] = '\0';
}
