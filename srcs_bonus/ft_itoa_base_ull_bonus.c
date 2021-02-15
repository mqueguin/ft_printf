/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_ull_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 18:37:25 by mqueguin          #+#    #+#             */
/*   Updated: 2021/02/15 09:48:48 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/ft_printf_bonus.h"

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
