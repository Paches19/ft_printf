/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:54:57 by adpachec          #+#    #+#             */
/*   Updated: 2022/10/17 11:31:59 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_param(char *arg, va_list *arg_ptr)
{
	int	len;

	len = 0;
	if (*arg == 'd' || *arg == 'i' || *arg == 'x' || *arg == 'X')
		len = ft_print_num(va_arg(*arg_ptr, int), arg);
	else if (*arg == 'c')
		len = ft_putchar((char) va_arg(*arg_ptr, int), 1);
	else if (*arg == 's')
		len = ft_putstr(va_arg(*arg_ptr, char *), 1);
	else if (*arg == 'u')
	{
		len = ft_print_uint(va_arg(*arg_ptr, unsigned int));
	}
	else if (*arg == 'p')
	{
		len += write(1, "0x", 2);
		len += ft_print_pointer(va_arg(*arg_ptr, unsigned long int), arg);
	}
	return (len);
}
