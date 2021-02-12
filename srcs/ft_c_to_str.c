/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_to_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 12:05:03 by mdupuis           #+#    #+#             */
/*   Updated: 2021/02/11 14:26:55 by mqueguin         ###   ########.fr       */
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
