/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <jbrown@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 08:58:50 by jbrown            #+#    #+#             */
/*   Updated: 2022/05/26 09:29:04 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*	Creates a new philosopher and assigns it the appropriate starting values.
	The philosopher is given a number, starting from 1. Once it has been
	initialised, the philosopher thread can begin its process in the function
	'philo_loop'.	*/

void	new_philo(t_shared share, int count)
{
	t_philo		*new;

	new = malloc(sizeof(*new));
	new->share = share;
	new->times_eaten = malloc(sizeof(int));
	new->times_eaten[0] = 0;
	new->left_fork = &share.forks[count];
	if (count + 1 != share.num_of_philos)
		new->right_fork = &share.forks[count + 1];
	else
		new->right_fork = &share.forks[0];
	new->number = count + 1;
	pthread_create(&(new->philo), NULL, philo_loop, new);
}

/*	Creates a mutex for every fork, equal to the number of philosophers.	*/

void	get_forks(t_shared *share)
{
	int	count;

	share->forks = malloc(sizeof(*share->forks) * share->num_of_philos);
	count = 0;
	while (count < share->num_of_philos)
	{
		pthread_mutex_init(&share->forks[count], NULL);
		count++;
	}
}

/*	Prepares forks for the philosophers, then loops until the philosophers
	have completed their tasks (may be an infinite loop if philosphers
	never starve and don't have a limit on times to eat).	*/

void	*init_philos(t_shared share)
{
	int		count;	

	if (!error_inputs(share))
		return (free_share(share));
	count = 0;
	share.start_time = get_time();
	while (count < share.num_of_philos)
	{
		new_philo(share, count);
		count++;
	}
	while (share.complete[0] != share.num_of_philos)
		;
	return (free_share(share));
}

/*	Each philosopher will share a range of values, saved in a structure.
	This function initialises these values, with the exception of start
	time, which is initialised when the first philosopher is ready to
	begin. If there has been no times_to_eat input, this value is set to
	zero.	*/

t_shared	set_values(int ac, char **av)
{
	t_shared		share;

	share.num_of_philos = ft_atoi(av[1]);
	share.time_to_die = ft_atoi(av[2]);
	share.time_to_eat = ft_atoi(av[3]);
	share.time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		share.times_to_eat = ft_atoi(av[5]);
	else
		share.times_to_eat = -2;
	share.dead = malloc(sizeof(*(share.dead)));
	share.dead[0] = 0;
	share.complete = malloc(sizeof(*(share.complete)));
	share.complete[0] = 0;
	share.fork_num = malloc(sizeof(*share.fork_num));
	share.fork_num = fork_numbers(share);
	share.talk = malloc(sizeof(*share.talk));
	pthread_mutex_init(share.talk, NULL);
	get_forks(&share);
	return (share);
}

/*	Checks if the correct number of inputs have been added. Then begins
	initialising the philosophers.	*/

int	main(int ac, char **av)
{
	if (ac != 5 && ac != 6)
	{
		error_check(0);
	}
	else
	{
		init_philos(set_values(ac, av));
	}
	return (0);
}
