/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 09:52:48 by mqueguin          #+#    #+#             */
/*   Updated: 2021/02/12 18:43:24 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*ft_add_fill(t_data *data)
{
	int		i;
	int		j;
	char	*fill;

	i = 0;
	j = 0;
	if (data->dot > data->len_variable - 2)
	{
		i = data->dot - (data->len_variable - 2);
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

static void	ft_special_cases(unsigned long long nbr, t_data *data, char *str)
{
	if (nbr == '\0' && data->b_dot == 1 && data->dot == 0)
	{
		str[0] = '\0';
		data->len_variable = 2;
	}
	data->len_variable = ((int)ft_strlen(str) + 2);
	if (data->width < data->dot)
		data->width = data->dot + 2;
}

static void	ft_treat_minus(t_data *data, char *str, char *space, char *fill)
{
	ft_add_to_buffer(data, "0x", 2);
	if (data->zero == 1)
		ft_add_to_buffer(data, space, data->len_space - data->len_fill);
	ft_add_to_buffer(data, fill, data->len_fill);
	ft_add_to_buffer(data, str, data->len_variable - 2);
}

void		ft_treat_pointer(unsigned long long nbr, t_data *data)
{
	char	*str;
	char	*space;
	char	*fill;

	fill = NULL;
	str = ft_itoa_base_ull(nbr);
	ft_special_cases(nbr, data, str);
	if (data->dot > (int)ft_strlen(str))
		fill = ft_add_fill(data);
	space = ft_treat_width(data);
	if (data->minus == 1)
		ft_treat_minus(data, str, space, fill);
	if (data->zero == 0 && data->len_space > 0)
		ft_add_to_buffer(data, space, data->len_space - data->len_fill);
	if (data->minus == 0)
		ft_treat_minus(data, str, space, fill);
	free(str);
	free(space);
	free(fill);
}
