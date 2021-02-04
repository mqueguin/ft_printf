/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 13:22:48 by mqueguin          #+#    #+#             */
/*   Updated: 2021/02/04 12:32:23 by mqueguin         ###   ########.fr       */
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
	int			i;
	int			ret_len;
	int			len_variable;
	int			len_space;
	int			b_dot;
	char		buffer[1024];
}				t_data;

int		ft_printf(const char *format, ...);
int		ft_parser(char *str, t_data *data, va_list args);
void	ft_exec_flags(char type, t_data *data, va_list args);

int		ft_check_buffer(t_data *data);
int		ft_check_flags(char c);
int		ft_check_type(char c);

t_data	ft_is_minus(t_data data);
void	ft_reset_flags(t_data *data);
t_data	ft_is_star(t_data data, va_list args);
t_data	ft_is_dot(char *str, t_data *data, va_list args);
t_data	ft_is_number(char c, t_data data);

void	ft_treat_char(char c, t_data *data);
char	*ft_treat_width(t_data *data);

void	ft_treat_string(char *str, t_data *data);

void	ft_display_buffer(t_data *data);
void	ft_add_to_buffer(t_data *data, char *str, int len);
void	ft_noflags_buffer(t_data *data, char *str);
char	*ft_c_to_str(char c);
char	*ft_strncat(char *dest, char *src, unsigned int n);

/** Fonction debug **/
void	printf_struct(t_data data);

#endif
