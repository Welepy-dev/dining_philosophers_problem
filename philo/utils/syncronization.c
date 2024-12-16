
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syncronization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welepy <welepy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:16:42 by marcsilv          #+#    #+#             */
/*   Updated: 2024/12/16 14:31:34 by welepy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.c"

void	wait_for_philosophers(t_data *data)
{
	while (!get_bool(&data->general_mutex, &data->are_philosophers_ready))
		;
	
}
