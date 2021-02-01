/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_debug.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 18:01:12 by mqueguin          #+#    #+#             */
/*   Updated: 2021/02/01 18:03:31 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_struct(t_data data)
{
	printf("zero : %d\n", data.zero);
	printf("minus : %d\n", data.minus);
	printf("width : %d\n", data.width);
	printf("star : %d\n", data.star);
	printf("buffer : %s\n", data.buffer);
	printf("dot : %d\n", data.dot);
	printf("index : %d\n", data.index);
}
