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

static inline bool operation_check(t_operation operation)
{
	return (operation == lock || operation == UNLOCK || operation == DESTROY);
}

static void	mutex_error_handler(int status, t_operation operation)
{
	if (status == 0)
		return ;
	if (status == EINVAL && operation_check(operation))
		er("The value specified by mutex is invalid");
	else if (status == EINVAL && operation == INIT)
		er("The value specified by attr is invalid");
	else if (status == EDEADLK)
		er("A deadlock would occur if the thread blocked waiting for mutex");
	else if (status == EPERM)
		er("The current thread does not hold a lock on mutex");
	else if (status == ENOMEM)
		er("The process cannot allocate enough memory to creat another mutex");
	else if (status == EBUSY)
		er("Mutex is locked")
}

static void thread_error_handler(int status, t_operation operation
{
	if (status == 0)
		return ;
	if (status == EAGAIN)
		er("No resources to create another thread")
	if (status == EPERM)
}

void	mutex_handler(pthread_mutex_t *mutex, t_operation operation)
{
	if (operation == INIT)
		mutex_error_handler(pthread_mutex_init(mutex, NULL), operation);
	else if (operation == LOCK)
		mutex_error_handler(pthread_mutex_lock(mutex), operation);
	else if (operation == UNLOCK)
		mutex_error_handler(pthread_mutex_unlock(mutex), operation);
	else if (operation == DESTROY)
		mutex_error_handler(pthread_mutex_destroy(mutex), operation);
	else
		er("Operation code not identified");
}

static void	thread_handler(pthread_t *thread, void *(*func)(void *), \
	void *data, t_operation operation)
{
	if (operation == CREATE)

}
