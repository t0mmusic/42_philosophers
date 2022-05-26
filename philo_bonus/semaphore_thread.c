/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore_thread.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <jbrown@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 09:54:39 by jbrown            #+#    #+#             */
/*   Updated: 2022/05/26 09:27:11 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

/*	Continuously checks if the current philosopher has died. 
	Because this is a seperate thread of the philosopher process, it does
	not care about a sem_wait call in another thread, allowing the process
	to exit while it is still waiting for a semaphore.	*/

void	*check_death(void *info)
{
	t_shared	*share;

	share = info;
	share->time_left = get_elapsed_time(share) + share->time_to_die;
	while (1)
	{
		if (share->time_left <= get_time() - share->start_time)
		{
			sem_wait(share->print);
			printf("%5lims Philosopher %i died.\n",
				get_time() - share->start_time, share->current);
			sem_post(share->end);
			exit (0);
		}
		usleep(500);
	}
	return (0);
}

/*	Continuosly checks if the current philosopher has eaten enough times. 
	Because this is a seperate thread of the philosopher process, it does
	not care about a sem_wait call in another thread, allowing the process
	to exit while it is still waiting for a semaphore.	*/

void	*check_fed(void *info)
{
	t_shared	*share;

	share = info;
	while (1)
	{
		if (share->times_eaten == share->times_to_eat)
		{
			sem_wait(share->print);
			sem_post(share->end);
			exit (0);
		}
		usleep(500);
	}
}

/*	If a philosopher has eaten in less than half the time they have until
	they starve, they will wait 600 microseconds before attempting to
	eat again. This prevents starvation on odd numbers of philosopher.	*/

void	curtesy_wait(t_shared *share)
{
	if (get_elapsed_time(share) - share->start_time
		< share->time_to_die / 2)
		usleep(600);
}

/*	The philosopher sleeps for the appropriate amount of time, then begins
	thinking.	*/

void	philo_sleep(t_shared *share)
{
	long int	current_time;

	print_time(share, "is sleeping.", share->current);
	current_time = get_time();
	while (get_time() - current_time <= share->time_to_sleep)
	{
		usleep(500);
	}
	print_time(share, "is thinking.", share->current);
}

/*	The philosopher will take two forks when they are both available. Once they
	have been taken, the philosopher will eat for the appropriate amount of time.
	They will then release the forks for other philosophers to use.	*/

void	philo_eat(t_shared *share)
{
	long int	current_time;

	sem_wait(share->forks);
	print_time(share, "has taken a fork.", share->current);
	sem_wait(share->forks);
	print_time(share, "has taken a fork.", share->current);
	share->time_left = get_elapsed_time(share) + share->time_to_die;
	current_time = get_time();
	print_time(share, "is eating.", share->current);
	while (get_time() - current_time <= share->time_to_eat)
	{
		usleep(500);
	}
	sem_post(share->forks);
	sem_post(share->forks);
}
