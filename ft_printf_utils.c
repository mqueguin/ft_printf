/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 14:30:14 by mqueguin          #+#    #+#             */
/*   Updated: 2021/02/01 15:18:11 by mqueguin         ###   ########.fr       */
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
