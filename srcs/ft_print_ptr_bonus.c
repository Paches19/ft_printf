/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:04:20 by adpachec          #+#    #+#             */
/*   Updated: 2022/10/17 11:04:49 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_len_ptr(unsigned long int param)
{
	int	len;

	len = 0;
	while (param >= 16)
	{
		param /= 16;
		++len;
	}
	return (++len);
}

int	ft_put_pointer(unsigned long int param)
{
	int				len_print;
	const char		*hex_low = "0123456789abcdef";

	len_print = 0;
	if (param >= 16)
	{
		len_print += ft_put_pointer(param / 16);
		len_print += ft_put_pointer(param % 16);
	}
	else
		len_print += write(1, &hex_low[param], 1);
	return (len_print);
}

int	ft_print_ptr_jl(t_format *print_format, unsigned long int param, \
int width)
{
	int			len_print;
	const int	len_num = ft_len_ptr(param);

	len_print = 0;
	if (print_format->precision)
	{
		len_print += ft_print_precision(print_format, len_num);
		len_print += ft_put_pointer(param);
		while (len_num < width && print_format->precision < width--)
			len_print += write(1, " ", 1);
	}
	else
	{
		len_print += ft_put_pointer(param);
		len_print += ft_print_min_width(print_format, len_num, 1, width);
	}
	return (len_print);
}

int	ft_print_ptr_jr(t_format *print_format, int len_num, int width)
{
	int	len_print;

	len_print = 0;
	if (print_format->precision >= width)
		len_print += ft_print_precision(print_format, len_num);
	else if (print_format->precision && print_format->precision < width)
	{
		while (len_num < width && print_format->precision < width--)
			len_print += write(1, " ", 1);
		len_print += ft_print_precision(print_format, len_num);
	}
	else if (!print_format->precision && print_format->min_width)
		len_print += ft_print_min_width(print_format, len_num, 1, width);
	return (len_print);
}

int	ft_print_pointer_bonus(unsigned long int param, t_format *print_format)
{
	const int		len_num = ft_len_ptr(param);
	int				len_print;
	int				width;

	width = print_format->min_width - 2;
	len_print = 0;
	if (print_format->just_left)
		len_print += ft_print_ptr_jl(print_format, param, width);
	else
	{
		len_print += ft_print_ptr_jr(print_format, (int)len_num, width);
		len_print += ft_put_pointer(param);
	}
	return (len_print);
}
