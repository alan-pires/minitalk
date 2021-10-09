/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:12:27 by apires-d          #+#    #+#             */
/*   Updated: 2021/10/09 19:47:22 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	receive_sig(int sig, siginfo_t *siginfo, void *unused);
static void	ft_putnbr(int n);

int	main(void)
{
	struct sigaction	sa;
	int					pid;
	
	sa.sa_sigaction = receive_sig;
	sa.sa_flags = SA_SIGINFO;
	pid = getpid();
	write(1, "Server Process ID: ", 19);
	ft_putnbr(pid);
	write(1,"\n", 1);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (42)
		pause();
	return (0);
}

static void	receive_sig(int sig, siginfo_t *siginfo, void *unused)
{
	static int c;
	static int bit;

	(void)unused;
	if (!bit)
		bit = 128;
	if (sig == SIGUSR1)
		c += bit;
	else
		c += 0;
	bit /= 2;
	if (bit == 0)
	{
		write(1, &c, 1);
		c = 0;
	}
	kill(siginfo->si_pid, SIGUSR1);
}

static void	ft_putnbr(int n)
{
	char	id[12];
	int		i;

	i = 0;
	while (n)
	{
		id[i++] = (n % 10) + '0';
		n /= 10;
	}
	id[i] = '\0';
	while (i)
		write(1, &id[--i], 1);
	write(1, "\n", 2);
}
