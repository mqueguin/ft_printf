/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 09:52:48 by mqueguin          #+#    #+#             */
/*   Updated: 2021/02/05 12:36:45 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_get_len(unsigned long long nbr)
{
	int		len;

	len = 0;
	if (nbr == 0)
		return (0);
	while (nbr)
	{
		len++;
		nbr /= 16;
	}
	return (len);
}

char	*ft_itoa_base_ull(unsigned long long nbr)
{
	char	*hexa;
	int		len;
	char	*ret;
	
	len = ft_get_len(nbr);
	hexa = "0123456789abcdef";
	if (!(ret = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ret[len] = '\0';
	len--;
	if (nbr == 0)
		ret[0] = '0';
	while (nbr != 0)
	{
		ret[len--] = hexa[nbr % 16];
		nbr /= 16;
	}
	return (ret);
}

char	*ft_add_fill(t_data *data)
{
	int		i;
	int		j;
	char	*fill;

	i = 0;
	j = 0;
	if (data->dot > data->len_variable)
	{
		i = data->dot - data->len_variable - 2;
		data->len_fill = i;
		//fill = ft_calloc(i, sizeof(char));
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

void	ft_treat_pointer(unsigned long long nbr, t_data *data)
{
	char	*str;
	char	*space;
	char	*fill;
		
	fill = NULL;
	str = ft_itoa_base_ull(nbr);
	data->len_variable = ((int)ft_strlen(str) + 2);
	if (data->dot > (int)ft_strlen(str))
		fill = ft_add_fill(data);
	space = ft_treat_width(data);
	if (data->minus == 1)
	{
		ft_add_to_buffer(data, "0x", 2);
		ft_add_to_buffer(data, fill, data->len_fill);
		ft_add_to_buffer(data, str, data->len_variable - 2);
	}
	ft_add_to_buffer(data, space, data->len_space - data->len_fill);
	if (data->minus == 0)
	{
		ft_add_to_buffer(data, "0x", 2);
		ft_add_to_buffer(data, fill, data->len_fill);
		ft_add_to_buffer(data, str, data->len_variable - 2);
	}
	free(str);
	free(space);
	if (fill)
		free(fill);
}
