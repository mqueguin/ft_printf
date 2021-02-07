/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 13:33:34 by mqueguin          #+#    #+#             */
/*   Updated: 2021/02/07 15:56:32 by mqueguin         ###   ########.fr       */
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
	data->len_variable = 0;
	data->len_space = 0;
	data->b_dot = 0;
	data->len_fill = 0;
}

void	ft_exec_flags(char type, t_data *data, va_list args)
{
	if (type == 'c')
		ft_treat_char(va_arg(args, int), data);
	if (type == 's')
		ft_treat_string(va_arg(args, char*), data);
	if (type == '%')
		ft_treat_char('%', data);
	if (type == 'p')
		ft_treat_pointer(va_arg(args, unsigned long long), data);
}

int		ft_parser(char *str, t_data *data, va_list args)
{
	while (str[++data->i])
	{
		if (!ft_check_flags(str[data->i]) && !ft_check_type(str[data->i])
				&& !ft_isdigit(str[data->i]))
			break ;
		if (str[data->i] == '0' && data->minus == 0 && data->width == 0)
			data->zero = 1;
		if (str[data->i] == '-')
			*data = ft_is_minus(*data);
		if (str[data->i] == '*')
			*data = ft_is_star(*data, args);
		if (str[data->i] == '.')
			*data = ft_is_dot(str, data, args);
		if (ft_isdigit(str[data->i]))
			*data = ft_is_number(str[data->i], *data);
		if (ft_check_type(str[data->i]))
		{
			data->type = str[data->i];
			break ;
		}
	}
	return (data->i);
}

int		ft_printf(const char *format, ...)
{
	char	*str;
	t_data	data;
	va_list	args;

	data.index = 0;
	data.i = 0;
	data.ret_len = 0;
	str = ft_strdup(format);
	ft_bzero(data.buffer, 1024);
	va_start(args, format);
	while (str[data.i])
	{
		ft_reset_flags(&data);
		if (!str)
			break ;
		else if (str[data.i] == '%' && str[data.i + 1])
		{
			data.i = ft_parser(str, &data, args);
			if (ft_check_type(str[data.i]))
				ft_exec_flags((char)data.type, &data, args);
			else if (str[data.i])
				ft_noflags_buffer(&data, str);
		}
		else if (str[data.i] != '%' && str[data.i])
			ft_noflags_buffer(&data, str);
		data.i++;
	}
	va_end(args);
	free((char*)str);
	ft_display_buffer(&data);
//	printf("Valeur de retour de printf : %d\n", data.ret_len);
	return (data.ret_len);
}
