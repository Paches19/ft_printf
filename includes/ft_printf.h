/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:53:31 by adpachec          #+#    #+#             */
/*   Updated: 2022/10/17 15:00:15 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

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

int		ft_printf(char const *arg, ...);
int		ft_print_arg(char *arg, va_list *arg_ptr);
int		ft_cases_arg(char *arg, va_list *arg_ptr);
int		ft_parse_arg(char *arg, va_list *arg_ptr);
int		ft_len_num(int param, char type);
void	ft_putnbr(int n);
int		ft_putchar(char c, int fd);
int		ft_putstr(char *s, int fd);
int		ft_print_uint(unsigned int param);
int		ft_len_num(int param, char type);
int		ft_check_sign(int param);
int		ft_print_int(int param);
int		ft_print_num(int param, char *arg);
int		ft_print_hex(unsigned int param, char *arg);
void	ft_putnbr_hex(unsigned int n, char *arg);
int		ft_print_pointer(unsigned long int param, char *arg);
int		ft_get_int(char *arg);
int		ft_get_param(char *arg, va_list *arg_ptr);
void	ft_putnbr_u(unsigned int n);
int		ft_len_num_u(unsigned long param);

#endif