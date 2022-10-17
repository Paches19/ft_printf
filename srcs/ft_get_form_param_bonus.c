/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_form_param_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:54:09 by adpachec          #+#    #+#             */
/*   Updated: 2022/10/17 10:54:35 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_print_precision_str(t_format *print_format, int len, char *s)
{
	int			precision;
	int			len_print;

	len_print = 0;
	precision = print_format->precision;
	if (print_format->precision > 0 && len > 0 && print_format->precision < len)
	{
		while (precision-- > 0)
		{
			ft_putchar_fd(*s, 1);
			++s;
			++len_print;
		}
	}
	else if (print_format->precision >= len)
		len_print += ft_putstr(s, 1);
	else if (len > 0 && print_format->precision > 0)
		len_print += ft_putstr(s, 1);
	return (len_print);
}

int	ft_get_int(char *arg)
{
	char	*num_s;
	int		i;
	int		num;

	i = 0;
	i = 0;
	while (ft_isdigit(arg[i]))
		++i;
	num_s = (char *) malloc(i);
	if (!num_s)
		return (-1);
	i = 0;
	while (ft_isdigit(*arg))
	{
		num_s[i] = *arg;
		++i;
		++arg;
	}
	--arg;
	num_s[i] = '\0';
	num = ft_atoi((num_s));
	free(num_s);
	return (num);
}

void	ft_init_tformat(t_format *print_format)
{
	print_format->just_left = false;
	print_format->zeros = false;
	print_format->sharp = false;
	print_format->sign = false;
	print_format->space = false;
	print_format->precision = -1;
	print_format->min_width = 0;
}

int	ft_get_param(char *arg, va_list *arg_ptr, t_format *print_format)
{
	int	len;

	len = 0;
	if (*arg == 'd' || *arg == 'i' || *arg == 'x' || *arg == 'X')
		len = ft_print_num(va_arg(*arg_ptr, int), print_format, arg);
	else if (*arg == 'c')
		len = ft_print_char((char) va_arg(*arg_ptr, int), print_format);
	else if (*arg == 's')
		len = ft_print_string(va_arg(*arg_ptr, char *), print_format);
	else if (*arg == 'u')
	{
		len = ft_print_uint(va_arg(*arg_ptr, unsigned int), print_format);
	}
	else if (*arg == 'p')
	{
		len += write(1, "0x", 2);
		len += ft_print_pointer_bonus(va_arg(*arg_ptr, unsigned long int), \
		print_format);
	}
	return (len);
}

void	ft_get_format(char *arg, t_format *print_format)
{
	while (!ft_strchr("cspdiuxX%%", *arg) && *arg != '\0')
	{
		if (*arg == '-')
			print_format->just_left = true;
		else if (*arg == '0' && !ft_isdigit(arg[-1]))
			print_format->zeros = true;
		else if (*arg == '#')
			print_format->sharp = true;
		else if (*arg == '+')
			print_format->sign = true;
		else if (*arg == ' ')
			print_format->space = true;
		else if (*arg == '.')
			print_format->precision = ft_get_int(++arg);
		else if (*arg != '0' && ft_isdigit(*arg) && !print_format->min_width \
		&& print_format->precision == -1)
			print_format->min_width = ft_get_int(arg);
		else if (*arg == '%')
			write(1, "%%", 1);
		++arg;
		while (ft_isdigit(*arg) && print_format->min_width > 0 && \
		arg[-1] != '0')
			++arg;
	}
}
