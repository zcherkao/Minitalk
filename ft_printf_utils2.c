/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherkao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:13:42 by zcherkao          #+#    #+#             */
/*   Updated: 2021/12/03 17:21:47 by zcherkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexadr(void *nb)
{
	int	len;

	len = 2;
	write (1, "0x", 2);
	len += ft_puthexp ((unsigned long)nb);
	return (len);
}

int	ft_puthexp(unsigned long nb)
{
	char	*base;
	int		len;

	len = 0;
	base = "0123456789abcdef";
	if (nb > 15)
	{
		len += ft_puthexp (nb / 16);
		len += ft_puthexp (nb % 16);
	}
	else
		len += ft_putchar (base[nb]);
	return (len);
}

int	ft_putnbr(int nb)
{
	int	len;

	len = 0;
	if (nb == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	if (nb < 10 && nb >= 0)
		len += ft_putchar (nb + '0');
	else if (nb >= 10)
	{
		len += ft_putnbr (nb / 10);
		len += ft_putnbr (nb % 10);
	}
	else
	{
		len += ft_putchar ('-');
		len += ft_putnbr (nb * -1);
	}
	return (len);
}

int	ft_putstr(char *str)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	if (!str)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (str[i] != '\0')
	{
		len += ft_putchar (str[i]);
		i++;
	}
	return (len);
}
