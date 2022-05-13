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

/*	A modified version of atoi which only accepts positive numbers. If anything
	other than a numeric character is found, it will return -1 to indicate an
	error has occured.	*/

void	activity_time(int time)
{
	usleep(time);
}

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

int	*get_times(int ac, char **av)
{
	int	*times;
	int	count;

	times = malloc(sizeof(*times) * ac);
	count = 0;
	while (count < ac - 1)
	{
		times[count] = ft_atoi(av[count + 1]);
		if (times[count] < 0)
			return (NULL);
		printf("Input: %i\n", times[count]);
		count++;
	}
	times[count] = 0;
	return (times);
}

int	main(int ac, char **av)
{
	struct timeval	current_time;
	int				start_time;
	int				*times;

	gettimeofday(&current_time, NULL);
	times = get_times(ac, av);
	if (!times)
		return (1);
	start_time = current_time.tv_usec;
	printf("Seconds: %ld\nMicro Seconds: %d\n",
		current_time.tv_sec, current_time.tv_usec);
	gettimeofday(&current_time, NULL);
	printf("Time Elapsed: %d\n", current_time.tv_usec - start_time);
	return (0);
}
