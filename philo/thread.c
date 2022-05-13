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

/*	Get the number of philosophers and create a new t_philo for each one. The
	first has philo_number 1, left fork 1 and right fork 2. The next has
	philo_number 2, with left fork 2 and right fork 3. It continues in this 
	fashion until the final philosopher, who has right fork 1.	*/


/*	This is the function that each thread runs when they are created.
	It should keep track of what each philosopher is doing, whether their 
	forks are available, an whether they have exceeded time_to_die. It will
	only exit on the condition that the philosopher has eaten as many times
	as they need to.	*/

void	*my_thread_fun(void *vargp)
{
	sleep(1);
	printf("Printing GeeksQuiz from Thread \n");
	return (NULL);
}

int	main(void)
{
	pthread_t	thread_id;

	printf("Before Thread\n");
	pthread_create(&thread_id, NULL, my_thread_fun, NULL);
	pthread_join(thread_id, NULL);
	printf("After Thread\n");
	exit (0);
}
