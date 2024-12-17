/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization_and_assignment.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welepy <welepy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:19:09 by marcsilv          #+#    #+#             */
/*   Updated: 2024/12/17 19:21:25 by welepy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	fork_assignment(t_philo *philosopher, t_fork *fork, int pos)
{
	philosopher->left_fork = &fork[pos];
	philosopher->right_fork = &fork[(pos + 1) % philosopher->data->number_of_philosophers];
	if (philosopher->id % 2 == 0)
	{
		philosopher->right_fork = &fork[pos];
		philosopher->left_fork = &fork[(pos + 1) % philosopher->data->number_of_philosophers];
	}
}

void	initialization_and_assignment(t_data *data)
{
	int	i;

	i = -1;
	data->forks = h_malloc(sizeof(t_fork) * data->number_of_philosophers);
	data->philosopher = h_malloc(sizeof(t_philo) * data->number_of_philosophers);
	data->end = false;
	data->are_philosophers_ready = false;
	mutex_handler(&data->general_mutex, INIT);
	while (++i < data->number_of_philosophers)
	{
		mutex_handler(&data->forks[i].fork, INIT);
		data->forks[i].fork_id = i;
		data->philosopher[i].id = i + 1;
		data->philosopher[i].is_full = false;
		data->philosopher[i].meals = 0;
		data->philosopher[i].last_meal = 0;
		mutex_handler(&data->philosopher[i].philosopher_mutex, INIT);
		fork_assignment(&data->philosopher[i], &data->forks[i], i);
	}
}
