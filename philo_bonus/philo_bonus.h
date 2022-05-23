/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <jbrown@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 10:58:42 by jbrown            #+#    #+#             */
/*   Updated: 2022/05/23 16:19:44 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>
# include <semaphore.h>
# include <signal.h>

typedef struct s_shared
{
	pthread_t		thread;
	sem_t			*forks;
	sem_t			*print;
	sem_t			*end;
	int				*pid;
	int				num_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				times_to_eat;
	int				current;
	int				times_eaten;
	long int		time_left;
	long int		start_time;
}	t_shared;

t_shared	*set_values(int ac, char **av);

long int	ft_atoi(const char *str);
long int	get_time(void);
long int	get_elapsed_time(t_shared *share);
void		print_time(t_shared *share, char *activity, int number);
int			error_check(int error);
int			error_inputs(t_shared share);

void		*philo_loop(void *info);

int			*fork_numbers(t_shared share);

void		*free_share(t_shared share);
void		curtesy_wait(t_shared *share);

void		*check_fed(void *info);
void		*check_death(void *info);

#endif
