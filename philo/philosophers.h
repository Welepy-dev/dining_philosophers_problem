/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:16:42 by marcsilv          #+#    #+#             */
/*   Updated: 2024/10/26 16:49:30 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <math.h>
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
	int				last_eat;
	pthread_t		thread;
	t_data			*data;
}	t_philo;*/

typedef struct s_fork
{
	pthread_mutex_t	fork;
	int	fork_id
}	t_fork;


typedef struct s_philo
{
	int	id;
	long	meals;
	bool	is_full;
	long	last_meal;
	t_fork	*left_fork;
	t_fork	*right_fork;
	pthread_t	thread_id;
}	t_philo;

typedef struct s_data
{
	bool	end;
	long	start;
	t_fork	*forks;
	t_philo	*philos;
	long	t_to_die;
	long	t_to_eat;
	long	nb_philos;
	long	t_to_sleep;
	long	meal_limit;
}	t_data;

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

void	p_err(char *s);
void	wrong_args(void);
void	*h_malloc(size_t size);
void	parse_args(int ac, char **av, t_data *data);

#endif