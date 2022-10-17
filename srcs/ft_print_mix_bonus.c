/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_mix_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:03:20 by adpachec          #+#    #+#             */
/*   Updated: 2022/10/17 11:03:33 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_putnbr(int n)
{
	long	temp;

	temp = n;
	if (temp < 0)
		temp *= -1;
	if (temp >= 10)
	{
		ft_putnbr(temp / 10);
		ft_putnbr(temp % 10);
	}
	else
		ft_putchar_fd(temp + '0', 1);
}

int	ft_putstr(char *s, int fd)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		++i;
	}
	return (i);
}

int	ft_print_char(char param, t_format *print_format)
{
	int		print_len;
	int		width;

	print_len = 1;
	width = print_format->min_width;
	if (print_format->just_left)
	{
		write(1, &param, 1);
		while (1 < width)
		{
			print_len += write(1, " ", 1);
			--width;
		}
	}
	else if (!print_format->just_left)
	{
		print_len += ft_print_min_width(print_format, 1, 1, width);
		write(1, &param, 1);
	}
	return (print_len);
}

int	ft_print_string(void *param, t_format *print_format)
{
	int			print_len;
	int			width;
	char		*s;
	const int	string_len = (int) ft_strlen((char *) param);

	s = (char *) param;
	print_len = 0;
	width = print_format->min_width;
	if (print_format->just_left)
	{
		print_len += ft_print_precision_str(print_format, string_len, s);
		if (print_format->precision == -1)
			print_len += ft_putstr(s, 1);
		print_len += ft_print_min_width_str(print_format, string_len, 1, width);
	}
	else
	{
		print_len += ft_print_min_width_str(print_format, string_len, 1, width);
		print_len += ft_print_precision_str(print_format, string_len, s);
	}
	if (print_format->precision == -1 && !print_format->just_left)
		print_len += ft_putstr(s, 1);
	return (print_len);
}

int	ft_print_uint(unsigned int param, t_format *print_format)
{
	int			len_print;
	const int	len_num = ft_len_num_u((unsigned long) param);
	int			width;

	len_print = 0;
	width = print_format->min_width;
	if (!print_format->just_left)
	{
		len_print += ft_print_min_width(print_format, len_num, 1, width);
		len_print += ft_print_precision(print_format, len_num);
		ft_putnbr_u(param);
		len_print += len_num;
	}
	else
	{
		len_print += ft_print_precision(print_format, len_num);
		ft_putnbr_u(param);
		len_print += len_num;
		while (len_num < width)
		{
			len_print += write(1, " ", 1);
			--width;
		}
	}
	return (len_print);
}
