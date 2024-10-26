/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:20:18 by marcsilv          #+#    #+#             */
/*   Updated: 2024/10/26 16:44:28 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	mutex_handler(pthread_mutex_t *mutex, t_operation opreation_code)
{
	if (LOCK == opreation_code)
		pthread_mutex_lock(mutex);
		
}