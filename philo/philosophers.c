/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:16:37 by marcsilv          #+#    #+#             */
/*   Updated: 2024/10/26 16:15:23 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_data data;

	if (ac == 5 || ac == 6)
	{
		parse_args(ac, av, &data);
		initialization_and_assignment(&data);
		start_simulation(&data);
		clean_and_exit(&data);
	}
	else
		wrong_args();
	return (0);
}

