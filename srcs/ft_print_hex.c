/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:57:22 by adpachec          #+#    #+#             */
/*   Updated: 2022/10/17 10:57:42 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer(unsigned long int param, char *arg)
{
	const char		*hex_low = "0123456789abcdef";
	int				len;

	len = 0;
	if (param >= 16)
	{
		len += ft_print_pointer(param / 16, arg);
		len += ft_print_pointer(param % 16, arg);
	}
	else
		len += write(1, &hex_low[param], 1);
	return (len);
}

void	ft_putnbr_hex(unsigned int n, char *arg)
{
	unsigned long	temp;
	const char		*hex_low = "0123456789abcdef";
	const char		*hex_up = "0123456789ABCDEF";

	temp = n;
	if (temp >= 16)
	{
		ft_putnbr_hex((unsigned int) temp / 16, arg);
		ft_putnbr_hex((unsigned int) temp % 16, arg);
	}
	else
	{
		if (*arg == 'x')
			write(1, &hex_low[temp], 1);
		else
			write(1, &hex_up[temp], 1);
	}
}

int	ft_print_hex(unsigned int param, char *arg)
{
	const int	len_num = ft_len_num((int) param, *arg);
	int			len_print;

	len_print = 0;
	ft_putnbr_hex(param, arg);
	len_print += len_num;
	return (len_print);
}
