/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:32:36 by marcsilv          #+#    #+#             */
/*   Updated: 2024/10/25 17:47:43 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	init(t_data *data)
{
	pthread_mutex_t	*forks;
	pthread_t	*philosophers;

	forks = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	philosophers = malloc(sizeof(pthread_t) * data->nb_philo);
	
}

