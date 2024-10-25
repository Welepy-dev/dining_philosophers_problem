/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:18:42 by marcsilv          #+#    #+#             */
/*   Updated: 2024/10/25 17:25:58 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	arg_validation(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	if (ac != 5 && ac != 6)
	{
		write(2, "Error: wrong number of arguments, correct way:", 46);
		write(2, " ./philosophers ", 16);
		write(2, "[n_philo] [t_to_die] [t_to_eat] [t_to_sleep]", 44);
		p_err(" [n_must_eat]");
	}
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				p_err("Error: arguments must be integers");
			j++;
		}
		i++;
	}
}

void	check_values(t_data *data, int ac)
{
	if (data->nb_philo < 1)
		p_err("Error: number of philosophers must be at least 1");
	if (data->time_to_die < 60)
		p_err("Error: time to die must be at least 60ms");
	if (data->time_to_eat < 60)
		p_err("Error: time to eat must be at least 60ms");
	if (data->time_to_sleep < 60)
		p_err("Error: time to sleep must be at least 60ms");
	if (ac == 6 && data->nb_must_eat < 1)
		p_err("Error: each philosopher eat must be at least 1 time");
}

void	check_assignment(t_data *data)
{
	if (data->nb_philo < 0 || data->time_to_die < 0 || \
	data->time_to_eat < 0||  data->time_to_sleep < 0)
		p_err("Error: All arguments must be postive integers");
}