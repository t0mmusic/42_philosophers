/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <jbrown@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:10:26 by jbrown            #+#    #+#             */
/*   Updated: 2022/05/19 15:38:11 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
