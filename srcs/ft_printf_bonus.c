/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:05:09 by adpachec          #+#    #+#             */
/*   Updated: 2022/10/17 12:00:41 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_print_min_width_str(t_format *print_format, int len, int param, \
int width)
{
	int	len_print;

	len_print = 0;
	if (param < 0 || print_format->sign)
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

int	ft_parse_arg(char *arg, va_list *arg_ptr)
{
	t_format	*print_format;
	int			len;
	char const	*conversors = "cspdiuxX";

	++arg;
	print_format = (t_format *) malloc(sizeof(t_format) * 1);
	if (!print_format)
		return (-1);
	ft_init_tformat(print_format);
	ft_get_format(arg, print_format);
	while (!ft_strchr(conversors, *arg))
		++arg;
	len = ft_get_param(arg, arg_ptr, print_format);
	free(print_format);
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
	char const	*conversors = "cspdiuxX";

	len = 0;
	temp = NULL;
	while (*arg != '\0')
	{
		temp = arg;
		aux = ft_cases_arg(arg, arg_ptr);
		if (aux < 0)
			return (-1);
		len += aux;
		if (*temp == '%' && temp[1] != '\0' && arg[1] != '\0')
		{
			++arg;
			while (!ft_strchr(conversors, *arg) && *arg != '\0')
				++arg;
		}
		if (*arg != '\0')
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
