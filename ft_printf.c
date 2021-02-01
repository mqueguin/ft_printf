/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 13:33:34 by mqueguin          #+#    #+#             */
/*   Updated: 2021/02/01 18:24:27 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_reset_flags(t_data *data)
{
	data->minus = 0;
	data->star = 0;
	data->zero = 0;
	data->dot = 0;
	data->width = 0;
	data->type = 0;
}

void	ft_exec_flags(t_data *data, va_list args)
{
	if (data->type == 'c')
		ft_treat_char(va_arg(args, int), data);
}

int		ft_parser(char *str, int i, t_data *data, va_list args)
{
	while (str[++i])
	{
		if (!ft_check_flags(str[i]) && !ft_check_type(str[i])
				&& !ft_isdigit(str[i]))
			break ;
		if (str[i] == '0' && data->minus == 0 && data->width == 0)
			data->zero = 1;
		if (str[i] == '-')
			*data = ft_is_minus(*data);
		if (str[i] == '*')
			*data = ft_is_star(*data, args);
		if (str[i] == '.')
			i = ft_is_dot(str, i, *data, args);
		if (ft_isdigit(str[i]))
			*data = ft_is_number(str[i], *data);
		if (ft_check_type(str[i]))
		{
			data->type = str[i];
			break ;
		}
	}
	return (i);
}

int		ft_printf(const char *format, ...)
{
	char	*str;
	t_data 	data;
	int		len;
	va_list	args;
	int		i;

	data.index = 0;
	len = 0;
	i = -1;
	str = ft_strdup(format);
	ft_bzero(data.buffer, 1024);
	va_start(args, format);
	while (str[++i])
	{
		if ((int)ft_strlen(data.buffer) >= 1024)
			len += ft_check_buffer(&data);
		ft_reset_flags(&data);
		if (str[i] == '%' && str[i + 1])
		{
			i = ft_parser(str, i, &data, args);
			if (ft_check_type(str[i]))
				ft_exec_flags(&data, args);
		}
		else if (str[i] != '%' && str[i])
			data.buffer[data.index++] = str[i];
	}
	va_end(args);
	data.buffer[data.index] = '\0';
	len += (int)ft_strlen(data.buffer);
	write(1, data.buffer, (int)ft_strlen(data.buffer));
	printf("valeur de retour de len : %d\n", len);
	return (len);
}
