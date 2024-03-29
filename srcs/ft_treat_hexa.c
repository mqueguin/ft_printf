/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 11:27:42 by mqueguin          #+#    #+#             */
/*   Updated: 2021/02/15 10:09:48 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_get_size(unsigned long nbr)
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
		nbr /= 16;
	}
	return (len);
}

static char	*ft_is_min_or_maj(char *hexa, t_data *data)
{
	if (data->type == 'x')
		hexa = "0123456789abcdef";
	else if (data->type == 'X')
		hexa = "0123456789ABCDEF";
	return (hexa);
}

static char	*ft_itoa_hexa(unsigned int nbr, t_data *data)
{
	unsigned long	nb;
	char			*res;
	int				len;
	char			*hexa;

	nb = nbr;
	hexa = NULL;
	len = ft_get_size(nb);
	hexa = ft_is_min_or_maj(hexa, data);
	if (!(res = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	res[len--] = '\0';
	if (nb < 0)
	{
		res[0] = '-';
		nb *= -1;
	}
	if (nb == 0)
		res[len--] = '0';
	while (nb > 0)
	{
		res[len--] = hexa[nb % 16];
		nb /= 16;
	}
	return (res);
}

static void	ft_special_cases(t_data *data, char *str, unsigned int nbr)
{
	if (nbr == 0 && data->b_dot == 1 && data->dot_exist == 1 && data->dot == 0)
		data->len_variable = 0;
	else if (nbr == 0 && data->b_dot == 1 && data->dot_exist == 0
			&& data->dot == 0)
		data->len_variable = 0;
	else
		data->len_variable = (int)ft_strlen(str);
	if (data->dot >= 0 && data->b_dot == 1 && data->dot < data->width
			&& data->zero == 1)
		data->zero = 0;
}

void		ft_treat_hexa(unsigned int nbr, t_data *data)
{
	char	*str;
	char	*space;
	char	*fill;

	space = NULL;
	str = ft_itoa_hexa(nbr, data);
	ft_special_cases(data, str, nbr);
	space = ft_treat_width(data);
	fill = ft_fill_u(data);
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
	free(fill);
}
