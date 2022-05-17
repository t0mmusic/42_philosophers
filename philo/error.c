/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <jbrown@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 15:32:11 by jbrown            #+#    #+#             */
/*   Updated: 2022/05/14 15:32:11 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*	Prints an error message based on the input error code. If an error was
	found, it will return a zero. Otherwise it will return 1.	*/

int	error_check(int error)
{
	if (!error)
	{
		printf("Incorrect Number of arguments!\n");
		return (0);
	}
	else if (error == -1)
	{
		printf("Inputs must be positive integer values.\n");
		return (0);
	}
	return (1);
}

/*	Checks if any of the input values were invalid. If any were, it will
	throw an error.	*/

int	error_inputs(t_shared share)
{
	if (share.num_of_philos < 0)
		return (error_check(-1));
	if (share.time_to_die < 0)
		return (error_check(-1));
	if (share.time_to_eat < 0)
		return (error_check(-1));
	if (share.time_to_sleep < 0)
		return (error_check(-1));
	if (share.times_to_eat == -1)
		return (error_check(-1));
	return (1);
}
