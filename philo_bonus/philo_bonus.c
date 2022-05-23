/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <jbrown@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:27:44 by jbrown            #+#    #+#             */
/*   Updated: 2022/05/23 17:01:57 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	split_process(int count, t_shared *share)
{
	pthread_t	thread;

	share->current = count;
	pthread_create(&thread, NULL, philo_loop, share);
	pthread_create(&thread, NULL, check_death, share);
	pthread_create(&thread, NULL, check_fed, share);
}

void	set_forks(t_shared *share)
{
	int	count;

	count = 0;
	while (count < share->num_of_philos)
	{
		share->pid[count] = fork();
		if (share->pid[count])
		{
			split_process(count + 1, share);
			break ;
		}
		count++;
	}
}

int	main(int ac, char **av)
{
	t_shared	*share;
	int			count;

	share = set_values(ac, av);
	share->pid = malloc(sizeof(*share->pid) * share->num_of_philos);
	share->start_time = get_time();
	set_forks(share);
	sem_wait(share->end);
	count = 0;
	while (count < share->num_of_philos)
	{
		kill(share->pid[count], SIGKILL);
		count++;
	}
	return (0);
}
