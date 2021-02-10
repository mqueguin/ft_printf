/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_u_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 16:50:54 by mqueguin          #+#    #+#             */
/*   Updated: 2021/02/10 10:17:33 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_get_size(unsigned long nb)
{
	int		len;

	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		nb *= -1;
	while (nb > 0)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

static char		*ft_uitoa(unsigned int nbr)
{
	char	*res;
	int		len;
	unsigned long nb;

	nb = nbr;
	len = ft_get_size(nb);
	if (!(res = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	res[len--] = '\0';
	if (nb < 0)
		nb *= -1;
	if (nb == 0)
		res[len] = '0';
	while (nb > 0)
	{
		res[len] = (nb % 10) + 48;
		nb /= 10;
		len++;
	}
	return (res);
}

char	*ft_fill_u(t_data *data, unsigned int nbr)
{
	char	*fill;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (data->dot > data->len_variable)
	{
		//if (nbr == -2147483648)
		//	i = data->dot - data->len_variable + 1;
		//else
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

void	ft_treat_u_int(unsigned int nbr, t_data *data)
{
	char	*str;
	char	*space;
	char	*fill;

	str = ft_uitoa(nbr);
	data->len_variable = (int)ft_strlen(str);
	space = ft_treat_width(data);
	fill = ft_fill_u(data, nbr);
	if (data->minus == 1)
	{
		ft_add_to_buffer(data, fill, data->len_fill);
		ft_add_to_buffer(data, str, data->len_variable);
	}
	ft_add_to_buffer(data, space, data->len_space - data->len_fill);
	if (data->minus == 0)
	{
		ft_add_to_buffer(data, fill, data->len_fill);
		ft_add_to_buffer(data, str, data->len_variable);
	}
	free(str);
	free(space);
	if (fill)
		free(fill);
}
