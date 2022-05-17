/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <jbrown@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 10:58:42 by jbrown            #+#    #+#             */
/*   Updated: 2022/05/13 16:10:31 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>

typedef struct s_shared
{
	int			num_of_philos;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			times_to_eat;
	long int	start_time;
	int			*complete;
	int			*dead;
	int			*fork_num;
}	t_shared;

typedef struct s_philo
{
	pthread_t		philo;
	int				number;
	long int		*time_left;
	int				*times_eaten;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	right_fork;
	t_shared		share;
}	t_philo;

long int	ft_atoi(const char *str);
long int	get_time(void);
long int	get_elapsed_time(t_philo philo);
void		print_time(t_philo philo, char *activity);
int			error_check(int error);
int			error_inputs(t_shared share);

void		*philo_loop(void *info);

int			*fork_numbers(t_shared share);

void		*free_philo(t_philo *philo);
void		*free_share(t_shared share);

#endif
