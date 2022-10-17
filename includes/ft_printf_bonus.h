/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:48:22 by adpachec          #+#    #+#             */
/*   Updated: 2022/10/17 15:00:08 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "stdbool.h"
# include <stdarg.h>
# include "unistd.h"
# include "../libft/libft.h"

typedef struct s_format
{
	bool	just_left;
	bool	zeros;
	bool	sharp;
	bool	sign;
	bool	space;
	int		precision;
	int		min_width;
}			t_format;

int		ft_print_pointer_bonus(unsigned long int param, t_format *print_format);
int		ft_put_pointer(unsigned long int param);
int		ft_print_ptr_jl(t_format *print_format, unsigned long int param, \
int width);
int		ft_print_ptr_jr(t_format *print_format, int len_num, int width);
int		ft_len_num(int param, char type);
int		ft_print_min_width(t_format *print_format, int len, int param, \
int width);
int		ft_print_precision(t_format *print_format, int len);
int		ft_printf(char const *arg, ...);
int		ft_print_arg(char *arg, va_list *arg_ptr);
int		ft_cases_arg(char *arg, va_list *arg_ptr);
int		ft_parse_arg(char *arg, va_list *arg_ptr);
void	ft_putnbr(int n);
int		ft_putstr(char *s, int fd);
int		ft_print_char(char param, t_format *print_format);
int		ft_print_string(void *param, t_format *print_format);
int		ft_print_uint(unsigned int param, t_format *print_format);
int		ft_check_sign(int param, t_format *print_format);
int		ft_print_int_jl(t_format *print_format, int param, const int len_num, \
int width);
int		ft_print_int_jr(t_format *print_format, int param, const int len_num, \
int width);
int		ft_print_int(int param, t_format *print_format);
int		ft_print_num(int param, t_format *print_format, char *arg);
int		ft_putnbr_hex(unsigned int n, char *arg);
int		ft_print_sharp( char *arg);
int		ft_print_hex_jl(t_format *print_format, int param, int width, \
char *arg);
int		ft_print_hex_jr(t_format *print_format, int width, \
char *arg, unsigned int param);
int		ft_print_hex(unsigned int param, t_format *print_format, char *arg);
int		ft_get_int(char *arg);
void	ft_init_tformat(t_format *print_format);
int		ft_get_param(char *arg, va_list *arg_ptr, t_format *print_format);
void	ft_get_format(char *arg, t_format *print_format);
void	ft_putnbr_u(unsigned int n);
int		ft_len_num_u(unsigned long param);
int		ft_len_ptr(unsigned long int param);
int		ft_print_precision_str(t_format *print_format, int len, char *s);
int		ft_print_min_width_str(t_format *print_format, int len, int param, \
int width);

#endif