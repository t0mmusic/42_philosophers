/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <jbrown@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 15:12:23 by jbrown            #+#    #+#             */
/*   Updated: 2022/05/14 15:12:23 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*	A modified version of atoi which only accepts positive numbers. If anything
	other than a positive numeric character is found, it will return -1 to
	indicate an	error has occured.	*/

long int	ft_atoi(const char *str)
{
	int			i;
	long int	r;

	i = 0;
	r = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (str[i] - '0');
		i++;
	}
	if (str[i])
		return (-1);
	return (r);
}

/*	Returns the amount of time in milliseconds that the program has been
	running.	*/

long int	get_elapsed_time(t_philo philo)
{
	return (get_time() - philo.share.start_time);
}

/*	Returns the current time in milli seconds. 'gettimeofday' can provide two
	things; the time since the timer started in seconds (long int), and the time
	since the program started running in useconds (int). Because we want the
	time in milliseconds (long int), we convert both values to that format and
	add them together.	*/

long int	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

/*	Prints the current activity that a philosopher is doing with the
	appropriate timestamp and message.	*/

void	print_time(t_philo philo, char *activity)
{
	long int	current_time;

	current_time = get_time() - philo.share.start_time;
	printf("%li: Philosopher %i %s\n", current_time, philo.number, activity);
}
