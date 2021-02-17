/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 15:42:35 by mqueguin          #+#    #+#             */
/*   Updated: 2021/02/17 12:07:20 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_c_to_str(char c)
{
	char	*ret;

	ret = ft_calloc(2, sizeof(char));
	ret[0] = c;
	ret[1] = '\0';
	return (ret);
}

void	ft_treat_char(char c, t_data *data)
{
	char	*str;
	char	*space;

	str = NULL;
	str = ft_c_to_str(c);
	data->len_variable = 1;
	space = ft_treat_width(data);
	if (data->minus == 1)
		ft_add_to_buffer(data, str, data->len_variable);
	ft_add_to_buffer(data, space, data->len_space);
	if (data->minus == 0)
		ft_add_to_buffer(data, str, data->len_variable);
	free(str);
	free(space);
}
