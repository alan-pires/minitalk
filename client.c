/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:12:03 by apires-d          #+#    #+#             */
/*   Updated: 2021/10/09 19:31:30 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void		send_msg(char *msg, pid_t pid_server);
static int		ft_atoi(const char *nptr);
static size_t	ft_strlen(const char *s);

int	main(int argc, char **argv)
{
	int	pid_server;
	
	if (argc != 3 || !(ft_strlen(argv[2])))
	{
		write(2, "Usage: ./client PID MESSAGE\n", 28);
		return (1);
	}
	pid_server = ft_atoi(argv[1]);
	if (!pid_server)
	{
		write(2, "Unknow PID\n", 11);
		return (1);
	}
	send_msg(argv[2], pid_server);
	// while (42)
	// 	pause();
	return (0);
}

static void	send_msg(char *msg, pid_t pid_server)
{
	int	aux;
	int	c;

	aux = 0;
	while (*msg)
	{
		c = *msg;
		// signal(SIGUSR1, handle_client);
		while (aux++ < 8)
		{
			if (c % 2 == 0 || c == 0)
				kill(pid_server, SIGUSR1);
			else
				kill(pid_server, SIGUSR2);
			usleep(100);
			c /= 2;
		}
		msg++;
	}
}

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
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
