/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization_and_assignment.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:19:09 by marcsilv          #+#    #+#             */
/*   Updated: 2024/10/26 16:53:12 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*void	initialization_and_assignment(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(t_fork) * data->nb_philos);
	data->philos = malloc(sizeof(t_philo) * data->nb_philos);
	pthread_mutex_init(&data->print_mutex, NULL);
	pthread_mutex_init(&data->death_mutex, NULL);
	while (i < data->nb_philos)
	{
		data->forks[i].fork_id = i;
		pthread_mutex_init(&data->forks[i].fork, NULL);
		data->philos[i].id = i;
		data->philos[i].meals = 0;
		data->philos[i].is_full = false;
		data->philos[i].last_eat = 0;
		data->philos[i].data = data;
		i++;
	}
	gettimeofday(&data->start, NULL);
}*/

void	initialization_and_assignment(t_data *data)
{
	data->forks = h_malloc(sizeof(t_fork) * data->nb_philos);
	data->philos = h_malloc(sizeof(t_philo) * data->nb_philos);
	data->end = false;
