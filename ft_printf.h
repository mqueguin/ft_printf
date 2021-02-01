/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 13:22:48 by mqueguin          #+#    #+#             */
/*   Updated: 2021/02/01 17:45:26 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct	s_data
{
	int			minus;
	int			star;
	int			zero;
	int			dot;
	int			width;
	int			index;
	int			type;
	char		buffer[1024];
}				t_data;

int		ft_printf(const char *format, ...);
int		ft_parser(char *str, int i, t_data *data, va_list args);
void	ft_exec_flags(t_data *data, va_list args);

int		ft_check_buffer(t_data *data);
int		ft_check_flags(char c);
int		ft_check_type(char c);

t_data	ft_is_minus(t_data data);
void	ft_reset_flags(t_data *data);
t_data	ft_is_star(t_data data, va_list args);
int		ft_is_dot(char *str, int i, t_data data, va_list args);
t_data	ft_is_number(char c, t_data data);

void	ft_treat_char(int c, t_data data);

void	ft_treat_width(t_data data, int minus);

#endif