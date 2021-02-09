/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 19:39:04 by mqueguin          #+#    #+#             */
/*   Updated: 2021/02/09 09:32:57 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_treat_int(int nbr, t_data *data)
{
	char	*str;
	char	*space;

	str = ft_itoa(nbr);
	data->len_variable = (int)ft_strlen(str);
	space = ft_treat_width(data);
	if (data->minus == 1)
		ft_add_to_buffer(data, str, data->len_variable);
	ft_add_to_buffer(data, space, data->len_space);
	if (data->minus == 0)
		ft_add_to_buffer(data, str, data->len_variable);
	free(str);
	free(space);
}
