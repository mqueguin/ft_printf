/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_int_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 19:39:04 by mqueguin          #+#    #+#             */
/*   Updated: 2021/02/17 12:00:25 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/ft_printf_bonus.h"

static char	*ft_fill(t_data *data, int nbr)
{
	char	*fill;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (data->dot > data->len_variable - 1)
	{
		if (nbr == -2147483648 || nbr < 0 || (nbr >= 0 && data->plus == 1))
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

static void	ft_special_cases(int nbr, t_data *data, char *str, char *fill)
{
	if (nbr == 0 && data->b_dot == 1 && data->dot == 0
			&& data->dot_exist == 0 && data->plus == 0)
		data->len_variable = 0;
	else if (nbr >= 0 && data->space == 1 && data->b_dot == 0 && data->width == 0)
	{
		data->len_variable = (int)ft_strlen(str);
		data->width = ((int)ft_strlen(str) + 1);
	}
	else if (nbr >= 0 && data->plus == 1)
	{
		if ((nbr == 0 && data->dot == 0 && data->dot_exist == 1 && data->b_dot == 1)
				|| (nbr == 0 && data->dot == 0 && data->b_dot == 1 && data->dot_exist == 0))
			data->len_variable = 1;
		else
			data->len_variable = (int)ft_strlen(str) + 1;
	}
	else if (nbr < 0 || (nbr >= 0 && data->plus == 1))
		data->len_variable = (int)ft_strlen(str) + 1;
	else if (nbr > 0)
		data->len_variable = (int)ft_strlen(str);
	else if (nbr == 0 && data->b_dot == 0)
		data->len_variable = 1;
	else if (nbr == 0 && data->b_dot == 1 && data->dot < 0
			&& data->dot_exist == 1)
		data->len_variable = 1;
	else if (nbr == 0 && data->dot_exist == 1 && data->dot > 0)
		data->len_variable = 1;
	if (data->width < data->dot)
	{
		if (nbr < 0 || (nbr >= 0 && data->plus == 1))
			data->width = data->dot + 1;
		else if (nbr > 0)
			data->width = data->dot;
	}
}

static void	ft_treat_minus_first(int nbr, t_data *data, char *space)
{
	if (nbr < 0 || (nbr >= 0 && data->plus == 1))
	{
		if (nbr < 0)
			ft_add_to_buffer(data, "-", 1);
		else if (data->plus == 1 && data->plus >= 0)
			ft_add_to_buffer(data, "+", 1);
		if (data->zero == 1)
			ft_add_to_buffer(data, space, data->len_space - data->len_fill);
	}
}

static void	ft_treat_minus_second(int nbr, t_data *data, char *str, char *fill)
{
	ft_add_to_buffer(data, fill, data->len_fill);
	if (nbr < 0 || (nbr >= 0 && data->plus == 1))
		ft_add_to_buffer(data, str, data->len_variable - 1);
	else
		ft_add_to_buffer(data, str, data->len_variable);
}

void		ft_treat_int(int nbr, t_data *data)
{
	char	*str;
	char	*space;
	char	*fill;

	fill = NULL;
	str = ft_itoa(nbr);
	ft_special_cases(nbr, data, str, fill);
	if (data->dot > (int)ft_strlen(str))
		fill = ft_fill(data, nbr);
	space = ft_treat_width(data);
	if (data->minus == 1)
	{
		if (data->space == 1 && nbr >= 0)
			ft_add_to_buffer(data, " ", 1);
		ft_treat_minus_first(nbr, data, space);
		ft_treat_minus_second(nbr, data, str, fill);
	}
	if ((data->zero == 0) || (data->zero == 1 && nbr >= 0 && data->plus == 0))
	{
		if (data->minus == 1 && data->space == 1 && nbr >= 0)
			ft_add_to_buffer(data, space, data->len_space - (data->len_fill + 1));
		else if (data->minus == 0 && data->space == 1 && nbr >= 0)
		{
			ft_add_to_buffer(data, " ", 1);
			ft_add_to_buffer(data, space, data->len_space - (data->len_fill + 1));
		}
		else
			ft_add_to_buffer(data, space, data->len_space - data->len_fill);
	}
	if (data->minus == 0)
	{
		ft_treat_minus_first(nbr, data, space);
		ft_treat_minus_second(nbr, data, str, fill);
	}
	free(fill);
	free(str);
	free(space);
}
