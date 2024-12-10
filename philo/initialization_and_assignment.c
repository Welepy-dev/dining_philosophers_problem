/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization_and_assignment.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welepy <welepy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:19:09 by marcsilv          #+#    #+#             */
/*   Updated: 2024/12/10 22:10:52 by welepy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*void	initialization_and_assignment(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(t_fork) * data->number_of_philos);
	data->philosopher = malloc(sizeof(t_philo) * data->number_of_philos);
	pthread_mutex_init(&data->print_mutex, NULL);
	pthread_mutex_init(&data->death_mutex, NULL);
	while (i < data->number_of_philos)
	{
		data->forks[i].fork_id = i;
		pthread_mutex_init(&data->forks[i].fork, NULL);
		data->philosopher[i].id = i;
		data->philosopher[i].meals = 0;
		data->philosopher[i].is_full = false;
		data->philosopher[i].last_meal = 0;
		data->philosopher[i].data = data;
		i++;
	}
	gettimeofday(&data->start, NULL);
}*/

static void	fork_assignment(t_philo *philosopher, t_fork *fork, int pos)
{
	philosopher->right_fork = &fork[pos];
	philosopher->left_fork = &fork[(pos + 1) % philosopher->data->number_of_philos];
}

void	initialization_and_assignment(t_data *data)
{
	int	i;

	i = -1;
	data->forks = h_malloc(sizeof(t_fork) * data->number_of_philos);
	data->philosopher = h_malloc(sizeof(t_philo) * data->number_of_philos);
	data->end = false;
	while (++i < data->number_of_philos)
	{
		mutex_handler(&data->forks[i].fork, INIT);
		data->forks[i].fork_id = i;
		data->philosopher[i].id = i + 1;
		data->philosopher[i].is_full = false;
		data->philosopher[i].meals = 0;
		data->philosopher[i].last_meal = 0;
	}
}
