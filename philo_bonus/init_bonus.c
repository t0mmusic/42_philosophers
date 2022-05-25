/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:15:20 by jbrown            #+#    #+#             */
/*   Updated: 2022/05/24 15:25:19 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

/*	Initialises three semaphores to be shared by the philosophers and the main
	process. Forks is the number of total forks that the philosophers can 
	share. print only allows one philosopher to print at a time, and will
	prevent philosophers from printing when one has died. End tells the main
	process that the child processes have finished and can be closed.	*/

void	set_sem(t_shared *share)
{
	sem_unlink("forks");
	sem_unlink("print");
	sem_unlink("end");
	share->forks = malloc(sizeof(share->forks));
	share->forks = sem_open("forks", O_CREAT | O_EXCL, S_IRWXU,
			share->num_of_philos);
	share->print = sem_open("print", O_CREAT | O_EXCL, S_IRWXU, 1);
	share->end = sem_open("end", O_CREAT | O_EXCL, S_IRWXU, 0);
}

/*	Each philosopher will share a range of values, saved in a structure.
	This function initialises these values, with the exception of start
	time, which is initialised when the first philosopher is ready to
	begin. If there has been no times_to_eat input, this value is set to
	zero.	*/

t_shared	*set_values(int ac, char **av)
{
	t_shared		*share;

	share = malloc(sizeof(*share));
	share->num_of_philos = ft_atoi(av[1]);
	share->time_to_die = ft_atoi(av[2]);
	share->time_to_eat = ft_atoi(av[3]);
	share->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		share->times_to_eat = ft_atoi(av[5]);
	else
		share->times_to_eat = -2;
	share->times_eaten = 0;
	set_sem(share);
	return (share);
}
