/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welepy <welepy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:16:42 by marcsilv          #+#    #+#             */
/*   Updated: 2024/12/17 19:21:08 by welepy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <math.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>

/*typedef struct s_data
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_must_eat;
	int				*forks;
	pthread_mutex_t	*forks_mutex;
	pthread_mutex_t	*philos_mutex;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	death_mutex;
	struct timeval	start;
}	t_data;

typedef struct s_philo
{
	int				id;
	int				nb_eat;
	int				last_meal;
	pthread_t		thread;
	t_data			*data;
}	t_philo;*/

typedef struct s_fork
{
	pthread_mutex_t	fork;
	int	fork_id
}	t_fork;

typedef struct s_data t_data;

typedef struct s_philo
{
	int	id;
	long	meals;
	bool	is_full;
	long	last_meal;
	t_fork	*left_fork;
	t_fork	*right_fork;
	pthread_t	thread_id;
	t_data	*data;
	pthread_mutex_t	philosopher_mutex;
}	t_philo;

struct s_data
{
	bool	end;
	long	start;
	t_fork	*forks;
	long	t_to_die;
	long	t_to_eat;
	long	t_to_sleep;
	long	meal_limit;
	t_philo	*philosopher;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	general_mutex;
	bool	are_philosophers_ready;
	long	number_of_philosophers;
};

typedef enum e_operation
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
} t_operation;

typedef enum e_status
{
	EATING,
	SLEEPING,
	THINKING,
	DEAD,
	FULL,
	TAKING_FIRST_FORK,
	TAKING_SECOND_FORK,
}	t_status;

typedef enum e_time
{
	SECOND,
	MILLISECOND,
	MICROSECOND
}	t_time;

void	er(char *s);
void	wrong_args(void);
void	*h_malloc(size_t size);
void	parse_args(int ac, char **av, t_data *data);
void	set_bool(pthread_mutex_t *mutex, bool *dest, bool value);
bool	get_bool(pthread_mutex_t *mutex, bool *value);
long	get_long(pthread_mutex_t *mutex, long *value);
void	set_long(pthread_mutex_t *mutex, long *dest, long value);
bool	simulation_finished(t_data *data);
void	status(t_philo *philosopher, t_status status, bool debug);
void	is_initialization_and_assignment(t_data *data);
void	wait_for_philosophers(t_data *data);
void	thread_handler(pthread_t *thread, void *(*func)(void *), \
	void *data, t_operation operation);
void	mutex_handler(pthread_mutex_t *mutex, t_operation operation);

#endif
