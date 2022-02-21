/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherkao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:30:19 by zcherkao          #+#    #+#             */
/*   Updated: 2022/01/11 11:59:26 by zcherkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <signal.h>
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
