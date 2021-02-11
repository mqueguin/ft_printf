/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 19:39:04 by mqueguin          #+#    #+#             */
/*   Updated: 2021/02/11 11:00:30 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_fill(t_data *data, int nbr)
{
	char	*fill;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (data->dot > data->len_variable)
	{
		if (nbr == -2147483648)
			i = data->dot - data->len_variable + 1;
		else
			i = data->dot - data->len_variable;
		data->len_fill = i;
		if (!(fill = (char*)malloc(sizeof(char) * (i + 1))))
			return (NULL);
		ft_bzero(fill, i + 1);
		while (i-- > 0)
			fill[j++] = '0';
		fill[j] = '\0';
		return (fill);
	}
	else
		return (NULL);
}

void	ft_treat_int(int nbr, t_data *data)
{
	char	*str;
	char	*space;
	char	*fill;

	fill = NULL;
	str = ft_itoa(nbr);
	if (nbr == 0 && data->b_dot == 1 && data->dot == 0 && data->dot_exist == 0)
		data->len_variable = 0;
	else if (nbr < 0)
		data->len_variable = (int)ft_strlen(str) + 1;
	else if (nbr > 0)
		data->len_variable = (int)ft_strlen(str);
	else if (nbr == 0 && data->b_dot == 0)
		data->len_variable = 1;
	else if (nbr == 0 && data->b_dot == 1 && data->dot < 0 && data->dot_exist == 1)
		data->len_variable = 1;
	if (data->width < data->dot)
	{
		if (nbr < 0)
			data->width = data->dot + 1;
		else if (nbr > 0)
			data->width = data->dot;
	}
	if (data->dot > (int)ft_strlen(str))
		fill = ft_fill(data, nbr);
	space = ft_treat_width(data);
	if (data->minus == 1)
	{
		if (nbr < 0)
		{
			ft_add_to_buffer(data, "-", 1);
			if (data->zero == 1)
				ft_add_to_buffer(data, space, data->len_space - data->len_fill);
		}
		ft_add_to_buffer(data, fill, data->len_fill);
		if (nbr < 0)
			ft_add_to_buffer(data, str, data->len_variable - 1);
		else
			ft_add_to_buffer(data, str, data->len_variable);
	}
	if ((data->zero == 0) || (data->zero == 1 && nbr >= 0))
		ft_add_to_buffer(data, space, data->len_space - data->len_fill);
	if (data->minus == 0)
	{
		if (nbr < 0)
		{
			ft_add_to_buffer(data, "-", 1);
			if (data->zero == 1)
				ft_add_to_buffer(data, space, data->len_space - data->len_fill);
		}
		ft_add_to_buffer(data, fill, data->len_fill);
		if (nbr < 0)
			ft_add_to_buffer(data, str, data->len_variable - 1);
		else
			ft_add_to_buffer(data, str, data->len_variable);
	}
	free(fill);
	free(str);
	free(space);
}
