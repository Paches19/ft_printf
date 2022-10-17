/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_mix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:03:52 by adpachec          #+#    #+#             */
/*   Updated: 2022/10/17 11:04:01 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	ft_putchar(char c, int fd)
{
	return (write(fd, &c, 1));
}

int	ft_putstr(char *s, int fd)
{
	int	i;

	if (!s)
		return (write(1, "(null)", 6));
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i], fd);
		++i;
	}
	return (i);
}

int	ft_print_uint(unsigned int param)
{
	const int	len_num = ft_len_num_u((unsigned long) param);

	ft_putnbr_u(param);
	return (len_num);
}
