/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 15:48:29 by mqueguin          #+#    #+#             */
/*   Updated: 2021/02/07 12:51:49 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_treat_width(t_data *data)
{
	char	*space;
	int		i;

	i = 0;
	if (data->dot > 0 && data->type == 's')
		data->len_variable = data->dot;
	if (data->type == 'p' && data->b_dot == 1)
		data->zero = 0;
	if (data->width < data->len_variable)
		return (NULL);
	if (!(space = ft_calloc((data->width - data->len_variable + 1), sizeof(char))))
		return (NULL);
	while (i < data->width - data->len_variable)
	{
		if (data->zero == 1)
			space[i] = '0';
		else if (data->zero == 0)
			space[i] = ' ';
		i++;
	}
	space[i] = '\0';
	data->len_space = i;
	return (space);
}
