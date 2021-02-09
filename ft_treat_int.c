/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 19:39:04 by mqueguin          #+#    #+#             */
/*   Updated: 2021/02/09 10:18:36 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_treat_int(int nbr, t_data *data)
{
	char	*str;
	char	*space;

	str = ft_itoa(nbr);
	if (nbr < 0)
		data->len_variable = (int)ft_strlen(str) + 1;
	else
		data->len_variable = (int)ft_strlen(str);

		//printf("Valeur de str : %s et valeur de len_variable : %d\n", str, data->len_variable);
	space = ft_treat_width(data);
	if (data->minus == 1)
	{
		if (nbr < 0)
		{
			ft_add_to_buffer(data, "-", 1);
			if (data->zero == 1)
				ft_add_to_buffer(data, space, data->len_space);
		}
		if (nbr < 0)
			ft_add_to_buffer(data, str, data->len_variable - 1);
		else
			ft_add_to_buffer(data, str, data->len_variable);
	}
	if (data->zero == 0 || (data->zero == 1 && nbr > 0))
	ft_add_to_buffer(data, space, data->len_space);
	if (data->minus == 0)
	{
		//printf("Ici\n");
		//printf("Valeur de str : %s et valeur de len_variable : %d\n", str, data->len_variable);
		if (nbr < 0)
		{
			ft_add_to_buffer(data, "-", 1);
			if (data->zero == 1)
				ft_add_to_buffer(data, space, data->len_space);
		}
		//printf("Valeur de str : %s et valeur de len_variable : %d\n", str, data->len_variable);
		if (nbr < 0)
			ft_add_to_buffer(data, str, data->len_variable - 1);
		else
			ft_add_to_buffer(data, str, data->len_variable);
	}
	free(str);
	free(space);
}
