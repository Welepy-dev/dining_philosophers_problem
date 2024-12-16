
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welepy <welepy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:16:42 by marcsilv          #+#    #+#             */
/*   Updated: 2024/12/16 14:31:34 by welepy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
* 0.1) if only one philosopher, ad hoc function
* 1) create all threads
* 2) syncro all threads
* 3) join all threads
*
* */

void	*dinner_simulation(void *dinner)
{
	t_philo	*philosopher;

	philosopher = (t_philo *)dinner;
	wait_for_philosophers(philosopher->data);
	return (NULL);
}

void	simulation(t_data *data)
{
	int	i;

	i = -1;
	if (data->meal_limit == 0)
		return ;
	if (data->number_of_philosophers == 1)
	{
		one_philosopher(data);
		return ;
	}
	while(++i < data->number_of_philosophers)
		thread_handler(&data->philosopher[i].thread_id, dinner_simulation, &data->philosopher[i], CREATE);
	data->start = get_time(MILLISECOND);
	set_bool(&data->general_mutex, &data->are_philosophers_ready, true);
	i = -1;
	while (++i < data->number_of_philosophers)
		thread_handler(&data->philosopher[i].thread_id, NULL, NULL, JOIN);
}
