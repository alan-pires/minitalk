/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:12:27 by apires-d          #+#    #+#             */
/*   Updated: 2021/10/16 19:55:58 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handle_sig(int sig);
static void	ft_putnbr(int n);

int	main(void)
{
	int	pid;

	pid = getpid();
	write(1, "Server listening on pid: ", 25);
	ft_putnbr(pid);
	write(1, "\n", 1);
	signal(SIGUSR1, handle_sig);
	signal(SIGUSR2, handle_sig);
	while (42)
		pause();
	return (0);
}

static void	handle_sig(int sig)
{
	static int	character;
	static int	bits;

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
