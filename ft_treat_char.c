/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 15:42:35 by mqueguin          #+#    #+#             */
/*   Updated: 2021/02/01 21:02:54 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_treat_char(char c, t_data *data)
{
	//printf_struct(*data);
	//printf("valeur de c : %c\n", c);
	if (c == '\0')
	{
		data->index++;
		ft_treat_width(data, 1);
		return ;
	}
	if (data->minus == 1)
		data->buffer[data->index++] = c;
	ft_treat_width(data, 1);
	if (data->minus == 0)
		data->buffer[data->index++] = c;
	data->buffer[data->index] = '\0';
	//printf("valeur de data.index : %d\n", data.index);
}
