/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:16:42 by marcsilv          #+#    #+#             */
/*   Updated: 2024/10/25 17:40:52 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data
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
}	t_philo;

void	p_err(char *s);
void	init(t_data *data);
void	check_assignment(t_data *data);
void	arg_validation(int ac, char **av);
void	check_values(t_data *data, int ac);
void	assignment(t_data *data, int ac, char **av);
void	validation(int ac, char **av, t_data *data);

int		ft_isdigit(int c);
int		ft_atoi(const char *str);

#endif