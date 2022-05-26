/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <jbrown@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 10:58:42 by jbrown            #+#    #+#             */
/*   Updated: 2022/05/26 09:25:23 by jbrown           ###   ########.fr       */
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
# include <fcntl.h>
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

/*	init_bonus.c	*/

void		set_sem(t_shared *share);
t_shared	*set_values(int ac, char **av);

/*	semaphore_thread.c	*/

void		curtesy_wait(t_shared *share);
void		*check_fed(void *info);
void		*check_death(void *info);
void		philo_eat(t_shared *share);
void		philo_sleep(t_shared *share);

/*	utils_bonus.c	*/

long int	ft_atoi(const char *str);
long int	get_time(void);
long int	get_elapsed_time(t_shared *share);
void		print_time(t_shared *share, char *activity, int number);
void		helpful_info(void);

#endif
