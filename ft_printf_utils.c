/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 14:30:14 by mqueguin          #+#    #+#             */
/*   Updated: 2021/02/04 13:57:53 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_check_flags(char c)
{
	return (c == '.' || c == '0' || c == '-' || c == '*');
}

int				ft_check_type(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
			|| c == 'u' || c == 'x' || c == 'X' || c == '%');
}

int				ft_check_buffer(t_data *data)
{
	int	len;

	len = 0;
	write(1, data->buffer, (int)ft_strlen(data->buffer));
	len = (int)ft_strlen(data->buffer);
	ft_bzero(data->buffer, 1024);
	return (len);
}

void			ft_display_buffer(t_data *data)
{
	write(1, data->buffer, data->index);
	data->index = 0;
}

void			ft_add_to_buffer(t_data *data, char *str, int len)
{
	int		i;
	
	i = 0;
	while (i < len)
	{
		data->buffer[data->index] = str[i];
		data->index++;
		if (data->index == 1024)
			ft_display_buffer(data);
		i++;
	}
	data->ret_len += len;
}

void			ft_noflags_buffer(t_data *data, char *str)
{
	int	len;

	len = 0;
	while (str[data->i] && str[data->i] != '%')
	{
		data->buffer[data->index] = str[data->i];
		data->index++;
		len++;
		if (data->index == 1024)
			ft_display_buffer(data);
		data->i++;
	}
	data->ret_len += len;
	data->i--;
}
