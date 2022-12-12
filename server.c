/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalwahei <jalwahei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:13:36 by jalwahei          #+#    #+#             */
/*   Updated: 2022/12/12 15:14:50 by jalwahei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

int	ft_printf(const char *str, ...);

void	handler(int sig)
{
	static char	byte;
	static int	bits_received;

	bits_received++;
	byte <<= 1;
	if (sig == SIGUSR1)
	byte |= 1;
	if (bits_received == 8)
	{
		write(1, &byte, 1);
		byte = 0;
		bits_received = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("\e[0;31mError: Wrong format \nTry ./server\n");
		return (0);
	}
	pid = getpid();
	ft_printf("\e[0;94mPID %d\n", pid);
	ft_printf("\e[0;94mWaiting for Message...\n");
	while (argc == 1)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
		pause ();
	}
	return (0);
}
