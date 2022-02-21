/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherkao <zcherkao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:07:23 by zcherkao          #+#    #+#             */
/*   Updated: 2022/01/13 18:41:20 by zcherkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_pid = 0;

void	reset(char *c, int *a, int pid)
{
	*c = 0xff;
	*a = 0;
	g_pid = pid;
}

void	handler(int sig, siginfo_t *info, void *context)
{
	static char		c = 0xff;
	static int		shiftt;

	(void)context;
	if (g_pid != info->si_pid)
		reset(&c, &shiftt, info->si_pid);
	if (sig == SIGUSR2)
		c |= 128 >> shiftt;
	else if (sig == SIGUSR1)
		c ^= 128 >> shiftt;
	shiftt++;
	if (shiftt == 8)
	{
		write(1, &c, 1);
		c = 0xff;
		shiftt = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("pid is : %d\n", getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
