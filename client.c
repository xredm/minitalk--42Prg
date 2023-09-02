/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xredm <xredm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 14:29:04 by xredm             #+#    #+#             */
/*   Updated: 2023/09/02 16:20:05 by xredm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	the_actual_thing(int s_pid, char c)
{
	int	bytes;

	bytes = 0;
	while (bytes < 8)
	{
		if (c & (0x01 << bytes))
			kill(s_pid, SIGUSR1);
		else
			kill(s_pid, SIGUSR2);
		usleep(721);
		bytes++;
	}
}

void	bit_received(int signum)
{
	if (signum == SIGUSR2)
		ft_printf("Received\n");
}

int	main(int ac, char **av)
{
	int	i;
	int	s_pid;

	i = 0;
	if (ac != 3)
	{
		ft_printf("I dont like your input, sorry! Try again later :D  \
		 (P.S. I know I am hilarious)\n");
		return (0);
	}
	(void)ac;
	s_pid = atoi(av[1]);
	signal(SIGUSR1, bit_received);
	signal(SIGUSR2, bit_received);
	while (av[2][i] != '\0')
	{
		the_actual_thing(s_pid, av[2][i]);
		i++;
	}
	the_actual_thing(s_pid, 0);
	return (0);
}
