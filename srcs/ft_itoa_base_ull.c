/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_ull.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 18:37:25 by mqueguin          #+#    #+#             */
/*   Updated: 2021/02/12 18:37:47 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
