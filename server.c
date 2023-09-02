/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xredm <xredm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 14:28:57 by xredm             #+#    #+#             */
/*   Updated: 2023/09/02 16:19:35 by xredm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signum, siginfo_t *info, void *context)
{
	static int	bytes;
	static int	c_pid;
	static char	c;

	(void)context;
	c_pid = info->si_pid;
	if (signum == SIGUSR1)
	{
		c |= (0x01 << bytes);
		bytes++;
	}
	else if (signum == SIGUSR2)
	{
		bytes++;
	}
	if (bytes == 8)
	{
		if (c == 0)
			kill(c_pid, SIGUSR2);
		else
			write(1, &c, 1);
		c = 0;
		bytes = 0;
	}
	kill(c_pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sa;

	(void)argc;
	(void)argv;
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	pid = getpid();
	sigemptyset(&sa.sa_mask);
	ft_putstr_fd(ft_itoa(pid), 1);
	write(1, "\n", 1);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
