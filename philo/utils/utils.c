/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:00:12 by marcsilv          #+#    #+#             */
/*   Updated: 2024/10/25 12:32:38 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	er(char *s)
{
	write(2, "Error: ", 7);
	while (*s)
	{
		write(2, s, 1);
		s++;
	}
	write(2, ".\n", 2);
	exit (1);
}

void	wrong_args(void)
{
	write(2, "Error:  Wrong input.\nTry ./philo ", 33);
	write(2, "n_philos t_to_die t_to_eat t_to_sleep [n_of_meals].\n", 52);
	write(2, "e.g: ./philo 5 800 200 200 5.\n", 30);
	write(2, "n_of_meals not required.\n", 25);
	exit(1);
}

void	*h_malloc(size_t size)
{
	void	*var;

	var = malloc(size);
	if (!var)
		er("Memory allocation failed");
	return (var);
}

long	get_time(t_time time_code)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		er("gettimeofday failed");
	if (time_code == SECOND)
		return (time.tv_sec + time.tv_usec / 1e6);
	if (time_code == MILLISECOND)
		return ((time.tv_sec * 1e3)+ (time.tv_usec / 1e3));
	if (time_code == MICROSECOND)
		return ((time.tv_sec * 1e6) + time.tv_usec);
	return (-1);
}
void	ft_usleep(long time, t_data *data)
{
	long	start;
	long	elapsed;
	long	rem;

	start = get_time(MICROSECOND);
	while (get_time(MICROSECOND) - start < time)
	{
		if (simulation_finished(&data))
			break ;
		elapsed = get_time(MICROSECOND) - start;
		rem = time - elapsed;
		if (rem > 1e3)
			usleep(1e3);
		else
		{
			while (get_time(MICROSECOND) - start < time)
				;
		}

}
