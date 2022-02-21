/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherkao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:04:57 by zcherkao          #+#    #+#             */
/*   Updated: 2021/12/05 15:48:38 by zcherkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_and_do(va_list args, char r)
{
	int	len;

	len = 0;
	if (r == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (r == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (r == 'd' || r == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (r == 'u')
		len += ft_put_nbr(va_arg(args, int));
	else if (r == 'x')
		len += ft_puthex(va_arg(args, unsigned int));
	else if (r == 'X')
		len += ft_put_hex(va_arg(args, unsigned int));
	else if (r == 'p')
		len += ft_puthexadr(va_arg(args, void *));
	return (len);
}

int	ft_printf(const char *frm, ...)
{
	int			len;
	int			i;
	va_list		args;

	len = 0;
	i = 0;
	va_start (args, frm);
	while (frm[i] != '\0')
	{
		if (frm[i] == '%')
		{
			i += 1;
			if (frm[i] == '%')
				len += ft_putchar('%');
			else
				len += ft_check_and_do(args, frm[i]);
		}
		else
			len += ft_putchar(frm[i]);
		i++;
	}
	va_end (args);
	return (len);
}

/*int main()
{
    int k=10;
    int j;
    int i;

    ft_printf("%p   %c   %s %%     ", &k, 'f', "Hello");
	"hwei hiwehd iwehud %d efiuhwiefhuwiefhuweifh"
    j = printf("%p", &k);
    printf("\n%d\n%d", i, j);
}*/
