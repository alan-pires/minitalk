/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:12:27 by apires-d          #+#    #+#             */
/*   Updated: 2021/10/12 21:46:04 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handle_sig(int sig, siginfo_t *siginfo, void *unused);
static void	ft_putnbr(int n);

int	main(void)
{
	struct sigaction	sa;
	int					pid;
	
	sa.sa_sigaction = handle_sig;
	sa.sa_flags = SA_SIGINFO;
	pid = getpid();
	write(1, "Server listening on pid: ", 25);
	ft_putnbr(pid);
	write(1,"\n", 1);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (42)
		pause();
	return (0);
}

static void	handle_sig(int sig, siginfo_t *siginfo, void *unused)
{
	static int character;
	static int bits;

	(void)unused;
	if (!bits)
		bits = 128;
	if (sig == SIGUSR1)
		character += bits;
	bits /= 2;
	if (!bits)
	{
		write(1, &character, 1);
		character = 0;
	}
	(void)siginfo;
	kill(siginfo->si_pid, SIGUSR1);
}

static void	ft_putnbr(int num)
{
	char	str_num[12];
	int		i;

	i = 0;
	while (num)
	{
		str_num[i++] = (num % 10) + '0';
		num /= 10;
	}
	str_num[i] = '\0';
	while (i)
		write(1, &str_num[--i], 1);
}
