/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherkao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:04:25 by zcherkao          #+#    #+#             */
/*   Updated: 2021/12/05 15:46:55 by zcherkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int	ft_putchar(int c);
int	ft_put_hex(unsigned int nb);
int	ft_put_nbr(unsigned int nb);
int	ft_puthex(unsigned int nb);
int	ft_puthexadr(void *nb);
int	ft_puthexp(unsigned long nb);
int	ft_putnbr(int nb);
int	ft_putstr(char *str);
int	ft_check_and_do(va_list args, char c);
int	ft_printf(const char *frm, ...);

#endif
