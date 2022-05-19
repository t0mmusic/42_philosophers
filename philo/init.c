/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <jbrown@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:16:38 by jbrown            #+#    #+#             */
/*   Updated: 2022/05/19 15:05:03 by jbrown           ###   ########.fr       */
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
