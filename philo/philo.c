/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <jbrown@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 08:58:50 by jbrown            #+#    #+#             */
/*   Updated: 2022/05/13 15:11:58 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*	Creates a new philosopher and assigns it the appropriate starting values.
	The philosopher is given a number, starting from 1. Once it has been
	initialised, the philosopher thread can begin its process in the function
	'philo_loop'.	*/

void	new_philo(t_shared share, pthread_mutex_t left,
	pthread_mutex_t right, int count)
{
	t_philo		*new;

	new = malloc(sizeof(*new));
	new->share = share;
	new->times_eaten = malloc(sizeof(int));
	new->times_eaten[0] = 0;
	new->left_fork = left;
	new->right_fork = right;
	new->number = count + 1;
	pthread_create(&(new->philo), NULL, philo_loop, new);
}

/*	Creates the appropriate number of philosophers. Each is given a left fork
	and a right fork. The left fork of each new philosopher is the same as
	the right fork of the previous, and the right fork of the last philospher
	is the left fork of the first. If any of the inputs have been set to
	negative one, an error is thrown and the program will end.
	NOTE: Need to add a method for destroying mutexes at end of program.	*/

void	*init_philos(t_shared share)
{
	pthread_mutex_t	left_fork;
	pthread_mutex_t	right_fork;
	pthread_mutex_t	first_fork;
	int				count;

	if (!error_inputs(share))
		return (free_share(share));
	pthread_mutex_init(&left_fork, NULL);
	first_fork = left_fork;
	count = 0;
	share.start_time = get_time();
	while (count < share.num_of_philos)
	{
		if (count + 1 != share.num_of_philos && share.num_of_philos > 1)
			pthread_mutex_init(&right_fork, NULL);
		else
			right_fork = first_fork;
		new_philo(share, left_fork, right_fork, count);
		count++;
		left_fork = right_fork;
		usleep(50);
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
	share.fork_num = fork_numbers(share);
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
