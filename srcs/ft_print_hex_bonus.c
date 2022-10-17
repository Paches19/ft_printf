/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:55:24 by adpachec          #+#    #+#             */
/*   Updated: 2022/10/17 11:16:49 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_putnbr_hex(unsigned int n, char *arg)
{
	unsigned long	temp;
	const char		*hex_low = "0123456789abcdef";
	const char		*hex_up = "0123456789ABCDEF";
	int				len_print;

	temp = n;
	len_print = 0;
	if (temp >= 16)
	{
		len_print += ft_putnbr_hex((unsigned int) temp / 16, arg);
		len_print += ft_putnbr_hex((unsigned int) temp % 16, arg);
	}
	else
	{
		if (*arg == 'x')
			len_print += write(1, &hex_low[temp], 1);
		else
			len_print += write(1, &hex_up[temp], 1);
	}
	return (len_print);
}

int	ft_print_sharp(char *arg)
{
	if (*arg == 'x' || *arg == 'p')
		write(1, "0x", 2);
	else
		write(1, "0X", 2);
	return (2);
}

int	ft_print_hex_jl(t_format *print_format, int param, int width, char *arg)
{
	int			len_print;
	const int	len_num = ft_len_num((int) param, *arg);

	len_print = 0;
	if (print_format->precision)
	{
		len_print += ft_print_precision(print_format, len_num);
		len_print += ft_putnbr_hex(param, arg);
		while (len_num < width && print_format->precision < width--)
			len_print += write(1, " ", 1);
	}
	if (!print_format->precision)
	{
		len_print += ft_putnbr_hex(param, arg);
		len_print += ft_print_min_width(print_format, len_num, 1, width);
	}
	return (len_print);
}

int	ft_print_hex_jr(t_format *print_format, int width, char *arg, \
unsigned int param)
{
	int			len_print;
	const int	len_num = ft_len_num((int) param, *arg);

	len_print = 0;
	if (print_format->precision >= width)
	{
		if (print_format->sharp && param != 0)
			len_print += ft_print_sharp(arg);
		len_print += ft_print_precision(print_format, len_num);
	}
	else if (print_format->precision > 0 && print_format->precision < width)
	{
		while (len_num < width && print_format->precision < width--)
			len_print += write(1, " ", 1);
		if (print_format->sharp && param != 0)
			len_print += ft_print_sharp(arg);
		len_print += ft_print_precision(print_format, len_num);
	}
	else
	{
		len_print += ft_print_min_width(print_format, len_num, 1, width);
		if (print_format->sharp && param != 0)
			len_print += ft_print_sharp(arg);
	}
	return (len_print);
}

int	ft_print_hex(unsigned int param, t_format *print_format, char *arg)
{
	int			width;
	int			len_print;

	width = print_format->min_width;
	len_print = 0;
	if (print_format->sharp)
		width -= 2;
	if (print_format->just_left)
	{
		if (print_format->sharp && param != 0)
			len_print += ft_print_sharp(arg);
		len_print += ft_print_hex_jl(print_format, param, width, arg);
	}
	else
	{
		len_print += ft_print_hex_jr(print_format, width, arg, \
		param);
		len_print += ft_putnbr_hex(param, arg);
	}
	return (len_print);
}
