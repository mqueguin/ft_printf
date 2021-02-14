/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 13:22:48 by mqueguin          #+#    #+#             */
/*   Updated: 2021/02/14 17:11:51 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
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
	int			space;
	int			plus;
	int			index;
	int			type;
	int			i;
	int			ret_len;
	int			len_variable;
	int			len_space;
	int			b_dot;
	int			dot_exist;
	int			len_fill;
	char		buffer[1024];
}				t_data;

int				ft_printf(const char *format, ...);
void			ft_parser(char *str, t_data *data, va_list args);
void			ft_exec_flags(char type, t_data *data, va_list args);
void			ft_reset_flags(t_data *data);
void			ft_transfer(t_data *data, char *str, va_list args);
int				ft_check_flags(char c);
int				ft_check_type(char c);
void			ft_display_buffer(t_data *data);
void			ft_add_to_buffer(t_data *data, char *str, int len);
void			ft_noflags_buffer(t_data *data, char *str);
t_data			ft_is_minus(t_data data);
t_data			ft_is_star(t_data data, va_list args);
t_data			ft_is_dot(char *str, t_data *data, va_list args);
t_data			ft_is_number(char c, t_data data);
char			*ft_treat_width(t_data *data);
void			ft_treat_char(char c, t_data *data);
char			*ft_c_to_str(char c);
void			ft_treat_string(char *str, t_data *data);
void			ft_treat_pointer(unsigned long long nbr, t_data *data);
char			*ft_itoa_base_ull(unsigned long long nbr);
int				ft_get_len(unsigned long long nbr);
char			*ft_add_fill(t_data *data);
void			ft_treat_int(int nbr, t_data *data);
void			ft_treat_u_int(unsigned int nbr, t_data *data);
char			*ft_fill_u(t_data *data, unsigned int nbr);
void			ft_treat_hexa(unsigned int nbr, t_data *data);

#endif
