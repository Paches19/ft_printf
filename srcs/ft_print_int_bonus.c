/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:57:57 by adpachec          #+#    #+#             */
/*   Updated: 2022/10/17 10:58:10 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_check_sign(int param, t_format *print_format)
{
	if (param < 0)
		return (write(1, "-", 1));
	else if (print_format->sign)
		return (write(1, "+", 1));
	else if (print_format->space && print_format->precision != 0)
		return (write(1, " ", 1));
	return (0);
}

int	ft_print_int_jl(t_format *print_format, int param, const int len_num, \
int width)
{
	int	len_print;

	len_print = 0;
	len_print += ft_check_sign(param, print_format);
	if (print_format->precision > 0)
	{
		len_print += ft_print_precision(print_format, len_num);
		if (print_format->space)
			len_print += write(1, " ", 1);
		if (print_format->precision != -1)
			ft_putnbr(param);
		while (print_format->precision < width && len_num < width)
		{
			len_print += write(1, " ", 1);
			--width;
		}
	}
	else
	{
		ft_putnbr(param);
		len_print += ft_print_min_width(print_format, len_num, param, width);
	}
	return (len_print);
}

int	ft_print_int_jr(t_format *print_format, int param, const int len_num, \
int width)
{
	int	len_print;

	len_print = 0;
	if (print_format->precision >= width && print_format->precision > 0)
	{
		len_print += ft_check_sign(param, print_format);
		len_print += ft_print_precision(print_format, len_num);
		ft_putnbr(param);
		len_print += len_num;
	}
	else
	{
		len_print += ft_check_sign(param, print_format);
		len_print += ft_print_min_width(print_format, len_num, param, width);
		len_print += ft_print_precision(print_format, len_num);
	}
	return (len_print);
}

int	ft_print_int(int param, t_format *print_format)
{
	int			len_print;
	const int	len_num = ft_len_num(param, 'i');
	int			width;
	int			precision;

	len_print = 0;
	width = print_format->min_width;
	precision = print_format->precision;
	if (print_format->just_left)
	{
		len_print += ft_print_int_jl(print_format, param, len_num, width);
		len_print += len_num;
	}
	else
		len_print += ft_print_int_jr(print_format, param, len_num, width);
	if (((len_print < width && width > len_num) || len_print < len_num || \
	(param < 0 && len_print < len_num + 1) || \
	(print_format->space == 1 && len_print < len_num + 1) || \
	(print_format->sign == 1 && len_print < len_num + 1)) && precision < 0)
	{
		ft_putnbr(param);
		len_print += len_num;
	}
	return (len_print);
}

int	ft_print_num(int param, t_format *print_format, char *arg)
{
	int	len_print;

	if (*arg == 'd' || *arg == 'i')
		len_print = ft_print_int(param, print_format);
	else
		len_print = ft_print_hex((unsigned int) param, print_format, arg);
	return (len_print);
}
