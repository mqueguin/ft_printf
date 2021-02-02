/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 15:42:35 by mqueguin          #+#    #+#             */
/*   Updated: 2021/02/02 14:52:40 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_treat_char(char c, t_data *data)
{
	char	*str;
	unsigned int		len;

//	printf_struct(*data);
	str = ft_c_to_str(c);
	len = 0;
	if (data->minus == 1)
	{
		ft_strncat(data->buffer, str, 1);
		data->index++;
	}
	if (data->width > 0)
		len = data->width - 1;
	data->ret_len += len;
	while (len > 0)
	{
		if (data->zero == 0)
			ft_strncat(data->buffer, " ", len);
		else if (data->zero == 1)
			ft_strncat(data->buffer, "0", len);
		data->index += len;
		len--;
	}
	if (data->minus == 0)
	{
		ft_strncat(data->buffer, str, 1);
		data->index++;
	}
	data->ret_len++;
}
