/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_error_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <jbrown@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:16:38 by jbrown            #+#    #+#             */
/*   Updated: 2022/05/26 09:36:22 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*	Sets up the appropriate number of forks for the philosophers. If there is
	only one, two forks are given. Any more and the number of forks is the
	same as the number of philosophers. Each of the fork indexes is given a
	value to indicate that the fork is currently available.	*/

int	*fork_numbers(t_shared share)
{
	int	*fork_num;
	int	count;

	if (share.num_of_philos == 1)
	{
		fork_num = malloc(sizeof(*fork_num) * 2);
		fork_num[0] = 0;
		fork_num[1] = 0;
	}
	else
	{
		fork_num = malloc(sizeof(*fork_num) * share.num_of_philos);
		count = 0;
		while (count < share.num_of_philos)
		{
			fork_num[count] = 1;
			count++;
		}
	}
	return (fork_num);
}

/*	Frees the malloced pointers in the shared structure.	*/

void	*free_share(t_shared share)
{
	int	count;

	free(share.dead);
	free(share.complete);
	free(share.fork_num);
	pthread_mutex_destroy(share.talk);
	free(share.talk);
	count = 0;
	while (count <= share.num_of_philos)
	{
		pthread_mutex_destroy(&share.forks[count]);
		count++;
	}
	free(share.forks);
	return (NULL);
}

/*	Frees the philosopher threads and the malloced pointers in the philosopher
	structure.	*/

void	*free_philo(t_philo *philo)
{
	pthread_join(philo->philo, NULL);
	free(philo->times_eaten);
	free(philo);
	return (NULL);
}

/*	Prints an error message based on the input error code. If an error was
	found, it will return a zero. Otherwise it will return 1.	*/

int	error_check(int error)
{
	if (!error || error == -1)
	{
		printf(" ------------------------------------------\n");
		printf("|   Unexpected or incorrect input!         |\n");
		printf("|   Expected 4 or 5 positive integers.     |\n");
		printf("|   1. Number of Philosopers.              |\n");
		printf("|   2. Time until starvation.              |\n");
		printf("|   3. Time it takes to eat.               |\n");
		printf("|   4. Time it takes to sleep.             |\n");
		printf("|   5. Number of times to eat (optional).  |\n");
		printf(" ------------------------------------------\n");
		return (0);
	}
	return (1);
}

/*	Checks if any of the input values were invalid. If any were, it will
	throw an error.	*/

int	error_inputs(t_shared share)
{
	if (share.num_of_philos <= 0)
		return (error_check(-1));
	if (share.time_to_die <= 0)
		return (error_check(-1));
	if (share.time_to_eat <= 0)
		return (error_check(-1));
	if (share.time_to_sleep <= 0)
		return (error_check(-1));
	if (share.times_to_eat <= 0 && share.times_to_eat != -2)
		return (error_check(-1));
	return (1);
}
