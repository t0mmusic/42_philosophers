/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <jbrown@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 09:13:49 by jbrown            #+#    #+#             */
/*   Updated: 2022/05/13 15:47:22 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*	Checks to see if the philosopher has exceeded the 'time_to_die', which is
	based on the last time the philospher ate. If they have, it over for all
	philosophers, and the shared 'dead' value is set to 1.	*/

int	check_death(t_philo philo)
{
	if (philo.share.dead[0])
		return (1);
	if (*(philo.time_left) <= get_elapsed_time(philo))
	{
		print_time(philo, "died.");
		philo.share.dead[0] = 1;
		return (1);
	}
	return (0);
}

/*	The philosopher sleeps in 50 usecond increments, each time checking if their
	'time-to-die' has expired. During this time, their is a check to see if the
	philosopher has finished sleeping. If the philosopher has finished sleeping
	without dying, they will begin thinking.	*/

void	philo_sleep(t_philo philo)
{
	long int	current_time;

	if (philo.share.dead[0])
		return ;
	print_time(philo, "is sleeping.");
	current_time = get_time();
	while (!check_death(philo))
	{
		if (get_time() - current_time >= philo.share.time_to_sleep)
			break ;
		usleep(50);
	}
	if (!philo.share.dead[0])
		print_time(philo, "is thinking.");
}

/*	The philosopher locks both the left and right fork, then begins eating.
	Once it is finished, it will unlock the forks again.	*/

void	eat(t_philo philo)
{
	if (philo.share.dead[0])
		return ;
	philo.share.fork_num[philo.number - 1] = 0;
	if (philo.number == philo.share.num_of_philos)
		philo.share.fork_num[0] = 0;
	else
		philo.share.fork_num[philo.number] = 0;
	print_time(philo, "has taken a fork.");
	pthread_mutex_lock(&(philo.left_fork));
	print_time(philo, "has taken a fork.");
	pthread_mutex_lock(&(philo.right_fork));
	print_time(philo, "is eating.");
	usleep(philo.share.time_to_eat * 1000);
	pthread_mutex_unlock(&(philo.left_fork));
	pthread_mutex_unlock(&(philo.right_fork));
	philo.share.fork_num[philo.number - 1] = 1;
	if (philo.number == philo.share.num_of_philos)
		philo.share.fork_num[0] = 1;
	else
		philo.share.fork_num[philo.number] = 1;
}

/*	Checks if the forks are currently available to the philosopher.	The forks
	that the current philosopher can access have the same index as the current
	philosopher, and that number minus one. The only exception is the final
	philosopher, who shares their fork with the first philosopher. A one
	indicates that the fork is available and a zero means it is not.	*/

int	check_lock(t_philo philo)
{
	if (philo.share.dead[0])
		return (0);
	if (!philo.share.fork_num[philo.number - 1])
	{
		return (0);
	}
	if (philo.number == philo.share.num_of_philos)
	{
		if (!philo.share.fork_num[0])
		{
			return (0);
		}
	}
	else if (!philo.share.fork_num[philo.number])
	{
		return (0);
	}
	return (1);
}

/*	This is the function that each thread runs when they are created.
	It should keep track of what each philosopher is doing, whether their
	forks are available, an whether they have exceeded time_to_die. It will
	only exit on the condition that the philosopher has eaten as many times
	as they need to.	*/

void	*philo_loop(void *info)
{
	t_philo		*philo;
	long int	time_left;

	philo = (t_philo *)info;
	time_left = get_elapsed_time(*philo) + philo->share.time_to_die;
	philo->time_left = &time_left;
	if (!check_lock(*philo))
		print_time(*philo, "is thinking.");
	while (!check_death(*philo))
	{
		if (!check_lock(*philo))
		{
			usleep(15000);
			continue ;
		}
		time_left = get_elapsed_time(*philo) + philo->share.time_to_die;
		philo->time_left = &time_left;
		eat(*philo);
		philo->times_eaten[0]++;
		if (philo->times_eaten[0] == philo->share.times_to_eat + 1)
			break ;
		philo_sleep(*philo);
	}
	philo->share.complete[0]++;
	return (free_philo(philo));
}
