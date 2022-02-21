/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherkao <zcherkao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:37:59 by zcherkao          #+#    #+#             */
/*   Updated: 2022/01/13 18:40:11 by zcherkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_strlen(char *s)
{
	int	i;

	i = -1;
	if (s)
	{
		i = 0;
		while (s[i])
			i++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' || str[i] == '\n'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - 48;
		i++;
	}
	return (result * sign);
}

void	send_bit_by_bit(int pid, char *msg, int len)
{
	int		shift;
	int		i;

	i = 0;
	while (i <= len)
	{
		shift = 0;
		while (shift < 8)
		{
			if (msg[i] & (128 >> shift))
			{
				if (kill(pid, SIGUSR2) == -1)
					exit (1);
			}
			else
			{
				if (kill(pid, SIGUSR1) == -1)
					exit (1);
			}
			shift++;
			usleep(800);
		}
		i++;
	}
}

void	handler(int sig)
{
	(void)sig;
	write(1, "ok\n", 3);
}

int	main(int ac, char **av)
{
	int					pid;

	if (ac != 3)
	{
		ft_printf("ERROR");
		exit(1);
	}
	if (ac == 3)
	{
		signal(SIGUSR1, handler);
		pid = ft_atoi(av[1]);
		send_bit_by_bit(pid, av[2], ft_strlen(av[2]));
	}
	return (0);
}
