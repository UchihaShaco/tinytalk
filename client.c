/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalwahei <jalwahei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:13:53 by jalwahei          #+#    #+#             */
/*   Updated: 2022/12/12 15:14:57 by jalwahei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

int		ft_atoi(const char *str);

void	send_signal(int n, int pid)
{
	int	byte_array[8];
	int	i;

	i = 0;
	while (i <= 7)
		byte_array[i++] = 0;
	i = 0;
	while (n > 0)
	{
		byte_array[i++] = n % 2;
		n /= 2;
	}
	i = 7;
	while (i >= 0)
	{
		if (byte_array[i--])
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
	}
}

int	main(int ac, char **av)
{
	int		pid;
	char	*message;
	int		i;

	i = 0;
	if (ac == 3)
	{
		while (av[1][i])
		{
			if (!(av[1][i] >= '0' && av[1][i] <= '9'))
				return (1);
			i++;
		}
		pid = ft_atoi(av[1]);
		message = av[2];
		while (*message)
			send_signal((int)*message++, pid);
	}
	return (0);
}