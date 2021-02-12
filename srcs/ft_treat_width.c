/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 15:48:29 by mqueguin          #+#    #+#             */
/*   Updated: 2021/02/12 15:36:27 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_treat_special_cases(t_data *data)
{
	if (data->dot > 0 && data->type == 's')
		data->len_variable = data->dot;
	if (data->type == 'p' && data->b_dot == 1 && data->dot >= 0)
		data->zero = 0;
	else if (data->type == 'd' && data->b_dot == 1 && data->dot >= 0)
		data->zero = 0;
	else if (data->type == 'i' && data->b_dot == 1 && data->dot >= 0)
		data->zero = 0;
}

char	*ft_treat_width(t_data *data)
{
	char	*space;
	int		i;

	i = 0;
	ft_treat_special_cases(data);
	if (data->width < data->len_variable)
		return (NULL);
	if (!(space = ft_calloc((data->width - data->len_variable + 1),
					sizeof(char))))
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
