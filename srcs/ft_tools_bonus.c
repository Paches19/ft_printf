/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:06:28 by adpachec          #+#    #+#             */
/*   Updated: 2022/10/17 11:06:57 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_len_num_u(unsigned long param)
{
	int	len;

	len = 0;
	while (param >= 10)
	{
		param /= 10;
		++len;
	}
	return (++len);
}

void	ft_putnbr_u(unsigned int n)
{
	unsigned long	temp;

	temp = n;
	if (temp < 0)
		temp *= -1;
	if (temp >= 10)
	{
		ft_putnbr_u(temp / 10);
		ft_putnbr_u(temp % 10);
	}
	else
		ft_putchar_fd(temp + '0', 1);
}

int	ft_len_num(int param, char type)
{
	unsigned int	temp;
	long			aux;
	int				len;

	len = 0;
	if (type == 'x' || type == 'X')
	{
		temp = param;
		while (temp >= 16)
		{
			temp /= 16;
			++len;
		}
		return (++len);
	}
	aux = (long)param;
	if (param < 0)
		aux *= -1;
	while (aux >= 10)
	{
		aux /= 10;
		++len;
	}
	return (++len);
}

int	ft_print_min_width(t_format *print_format, int len, int param, int width)
{
	int	len_print;

	len_print = 0;
	if (param < 0 || print_format->space || print_format->sign)
		width--;
	while (len < width--)
	{
		if (print_format->zeros)
			len_print += write(1, "0", 1);
		else
			len_print += write(1, " ", 1);
	}
	return (len_print);
}

int	ft_print_precision(t_format *print_format, int len)
{
	int			precision;
	int			len_print;

	len_print = 0;
	precision = print_format->precision;
	while (len < precision--)
		len_print += write(1, "0", 1);
	return (len_print);
}
