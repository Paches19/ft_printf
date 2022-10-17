/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:58:34 by adpachec          #+#    #+#             */
/*   Updated: 2022/10/17 11:02:34 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	ft_len_num(int param, char type)
{
	unsigned int	temp;
	long			aux;
	int				len;

	len = 0;
	if (type == 'x' || type == 'X' || type == 'p')
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

int	ft_check_sign(int param)
{
	if (param < 0)
		return (write(1, "-", 1));
	return (0);
}

int	ft_print_int(int param)
{
	int			len_print;
	const int	len_num = ft_len_num(param, 'i');

	len_print = ft_check_sign(param);
	ft_putnbr(param);
	len_print += len_num;
	return (len_print);
}

int	ft_print_num(int param, char *arg)
{
	int	len_print;

	if (*arg == 'd' || *arg == 'i')
		len_print = ft_print_int(param);
	else
		len_print = ft_print_hex((unsigned int) param, arg);
	return (len_print);
}
