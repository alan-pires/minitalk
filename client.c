/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:12:03 by apires-d          #+#    #+#             */
/*   Updated: 2021/10/12 21:45:15 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void		send_msg(char *msg, pid_t pid_server);
static int		ft_atoi(const char *nptr);
static void		handle_signal(int	sig);

int	main(int argc, char **argv)
{
	int	pid_server;

	if (argc != 3)
	{
		write(2, "Usage: ./client PID MESSAGE\n", 28);
		return (1);
	}
	pid_server = ft_atoi(argv[1]);
	if (pid_server < 0)
	{
		write(2, "Unknow PID\n", 11);
		return (1);
	}
	send_msg(argv[2], pid_server);
	return (0);
}

static void	send_msg(char *msg, pid_t pid_server)
{
	int	aux;

	while (*msg)
	{
		aux = 0;
		while (aux < 8)
		{
			signal(SIGUSR1, handle_signal);
			if (*msg & (128 >> aux))
				kill(pid_server, SIGUSR1);
			else
				kill(pid_server, SIGUSR2);
			aux++;
			sleep(1);
		}
		msg++;
	}
}

static void	handle_signal(int	sig)
{	
	(void)sig;
}

static int	ft_atoi(const char *nptr)
{
	int	i;
	int	nbr;
	int	signal;

	i = 0;
	nbr = 0;
	signal = 1;
	while (nptr[i] == '\f' || nptr[i] == '\n' || nptr[i] == '\r'
		|| nptr[i] == '\t' || nptr[i] == '\v' || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			signal = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nbr = nbr * 10 + (nptr[i] - '0');
		i++;
	}
	return (nbr * signal);
}
