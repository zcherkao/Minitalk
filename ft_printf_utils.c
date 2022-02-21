/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherkao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:11:10 by zcherkao          #+#    #+#             */
/*   Updated: 2021/12/03 17:26:40 by zcherkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_put_hex(unsigned int nb)
{
	char	*base;
	int		len;

	len = 0;
	base = "0123456789ABCDEF";
	if (nb > 15)
	{
		len += ft_put_hex (nb / 16);
		len += ft_put_hex (nb % 16);
	}
	else
		len += ft_putchar (base[nb]);
	return (len);
}

int	ft_put_nbr(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb < 10 && nb >= 0)
		len += ft_putchar (nb + '0');
	else if (nb >= 10)
	{
		len += ft_put_nbr (nb / 10);
		len += ft_put_nbr (nb % 10);
	}
	return (len);
}

int	ft_puthex(unsigned int nb)
{
	char	*base;
	int		len;

	len = 0;
	base = "0123456789abcdef";
	if (nb > 15)
	{
		len += ft_puthex (nb / 16);
		len += ft_puthex (nb % 16);
	}
	else
		len += ft_putchar (base[nb]);
	return (len);
}
