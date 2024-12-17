/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welepy <welepy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:58:54 by welepy            #+#    #+#             */
/*   Updated: 2024/12/17 19:19:57 by welepy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static void	debug_status(t_philo *philosopher, t_status status, long time)
{
	if (status == TAKING_FIRST_FORK)
		printf("%ld %d has taken first fork of number: %d\n", time, philosopher->id, philosopher->left_fork->fork_id);
	else if (status == TAKING_SECOND_FORK)
		printf("%ld %d has taken second fork of number: %d\n", time, philosopher->id, philosopher->right_fork->fork_id);
	else if (status == EATING)
		printf("%ld %d is eating\n", time, philosopher->id);
	else if (status == SLEEPING)
		printf("%ld %d is sleeping\n", time, philosopher->id);
	else if (status == THINKING)
		printf("%ld %d is thinking\n", time, philosopher->id);
	else if (status == DEAD)
		printf("%ld %d died\n", time, philosopher->id);
}

void	status(t_philo *philosopher, t_status status, bool debug)
{
	long	time;

	time = get_time(MILLISECOND) - philosopher->data->start;
	if (philosopher->is_full)
		return ;
	mutex_handler(&philosopher->data->print_mutex, LOCK);
	if (debug)
		debug_status(philosopher, status, time);
	else
	{
		if ((status == TAKING_FIRST_FORK || status == TAKING_SECOND_FORK) && !simulation_finished(philosopher->data))
			printf("%ld %d has taken a fork\n", time, philosopher->id);
		else if (status == EATING && !simulation_finished(philosopher->data))
			printf("%ld %d is eating\n", time, philosopher->id);
		else if (status == SLEEPING && !simulation_finished(philosopher->data))
			printf("%ld %d is sleeping\n", time, philosopher->id);
		else if (status == THINKING && !simulation_finished(philosopher->data))
			printf("%ld %d is thinking\n", time, philosopher->id);
		else if (status == DEAD && !simulation_finished(philosopher->data))
			printf("%ld %d died\n", time, philosopher->id);
	}
	mutex_handler(&philosopher->data->print_mutex, UNLOCK);
}