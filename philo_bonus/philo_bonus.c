/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:27:44 by jbrown            #+#    #+#             */
/*   Updated: 2022/05/25 20:24:10 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

/*	Creates two threads for each process; one which checks if the philosoper
	has died and one that checks if they have eaten enough times. The main
	thread then begins to cycle through eating, sleeping and thinking.	*/

void	split_process(int count, t_shared *share)
{
	pthread_t	thread;

	share->current = count;
	pthread_create(&thread, NULL, check_death, share);
	pthread_create(&thread, NULL, check_fed, share);
	while (1)
	{
		philo_eat(share);
		share->times_eaten++;
		philo_sleep(share);
		curtesy_wait(share);
	}
}

int	error_check(t_shared *share)
{
	if (share->num_of_philos <= 0)
		return (1);
	if (share->time_to_die <= 0)
		return (1);
	if (share->time_to_eat <= 0)
		return (1);
	if (share->time_to_sleep <= 0)
		return (1);
	if (share->times_to_eat == -1)
		return (1);
	return (0);
}

/*	Creates a new child process for each new philosopher. The
	parent process retains the PIDs of all of the new processes
	so that they can be closed later.	*/

void	set_forks(t_shared *share)
{
	int	count;

	count = 0;
	while (count < share->num_of_philos)
	{
		share->pid[count] = fork();
		if (!share->pid[count])
		{
			split_process(count + 1, share);
		}
		count++;
	}
}

void	pause_time(t_shared *share)
{
	int	count;
	
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
}

int	main(int ac, char **av)
{
	t_shared	*share;
	
	if (ac != 5 && ac != 6)
	{
		printf("Incorrect number of arguments.\n");
		return (1);
	}
	share = set_values(ac, av);
	if (error_check(share))
	{
		printf("Values not permitted.\n");
		return (1);
	}
	pause_time(share);
	return (0);
}
