/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 19:39:04 by mqueguin          #+#    #+#             */
/*   Updated: 2021/02/07 19:56:17 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_get_size(long nbr)
{
	int		len;

	len = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		len++;
		nbr *= -1;
	}
	while (nbr > 0)
	{
		len++;
		nbr /= 10;
	}
	return (len);
}

static char	*ft_itoa_int(int nbr)
{
	char	*res;
	int		len;

	len = ft_get_size(nbr);
	if (!(res = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	res[len--] = '\0';
	if (nbr == 0)
	{
		res[0] = '0';
		return (res);
	}
	if (nbr < 0)
	{
		res[0] = '-';
		nbr *= -1;
	}
	while (nbr > 0)
	{
		res[len--] = (nbr % 10) + 48;
		nbr /= 10;
	}
	return (res);
}

void	ft_treat_int(int nbr, t_data *data)
{
	char	*str;
	char	*space;

	str = ft_itoa_int(nbr);
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
