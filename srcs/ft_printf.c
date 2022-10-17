/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:05:58 by adpachec          #+#    #+#             */
/*   Updated: 2022/10/17 11:57:30 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_arg(char *arg, va_list *arg_ptr)
{
	int			len;

	++arg;
	len = ft_get_param(arg, arg_ptr);
	--arg;
	return (len);
}

int	ft_cases_arg(char *arg, va_list *arg_ptr)
{
	int	len;

	len = 0;
	if (arg[0] == '%' && arg[1] != '%' && \
	arg[1] > 31 && arg[1] != 127)
	{
		len = ft_parse_arg(arg, arg_ptr);
		return (len);
	}
	else if (arg[0] == '%' && arg[1] == '\0')
		return (0);
	return (write(1, &arg[0], 1));
}

int	ft_print_arg(char *arg, va_list *arg_ptr)
{
	int			len;
	int			aux;
	char		*temp;

	len = 0;
	temp = NULL;
	while (*arg != '\0')
	{
		temp = arg;
		aux = ft_cases_arg(arg, arg_ptr);
		if (aux < 0)
			return (-1);
		len += aux;
		if (*temp == '%' && temp[1] != '\0')
			++arg;
		++arg;
	}
	return (len);
}

int	ft_printf(char const *arg, ...)
{
	va_list	arg_ptr;
	int		len;
	char	*ag;

	if (!arg)
		return (-1);
	ag = (char *) arg;
	if (!ag)
		return (-1);
	va_start(arg_ptr, arg);
	len = ft_print_arg(ag, &arg_ptr);
	va_end(arg_ptr);
	return (len);
}
