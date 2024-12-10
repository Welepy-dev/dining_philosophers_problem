/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welepy <welepy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:20:18 by marcsilv          #+#    #+#             */
/*   Updated: 2024/12/10 21:55:25 by welepy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static inline bool operation_check(t_operation op)
{
	return (op == LOCK || op == UNLOCK || op == DESTROY);
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
		er("Will occur a deadlock if the thread waits for mutex");
	else if (status == EPERM)
		er("The current thread does not hold a lock on mutex");
	else if (status == ENOMEM)
		er("The process havent enough memory to create another mutex");
	else if (status == EBUSY)
		er("Mutex is locked");
}

static void thread_error_handler(int status, t_operation operation)
{
	if (status == 0)
		return ;
	if (status == EAGAIN)
		er("No resources to create another thread");
	else if (status == EPERM)
		er("The caller does not have appropriate permission");
	else if (status == EINVAL && operation == CREATE)
		er("The value specified by attr is invalid");
	else if (status == EINVAL && (operation == JOIN || operation == DETACH))
		er("Thread is not joinable");
	else if (status == ESRCH)
		er("No thread was found corresponding to that specified ID");
	else if (status == EDEADLK)
		er("Deadlock found or thread value specify the calling thread");
	else if (status == ENOMEM)
		er("The process havent enough memory to create another thread");
	
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

void	thread_handler(pthread_t *thread, void *(*func)(void *), \
	void *data, t_operation operation)
{
	if (operation == CREATE)
		thread_error_handler(pthread_create(thread, NULL, func, data), \
		operation);
	else if (operation == JOIN)
		thread_error_handler(pthread_join(*thread, NULL), operation);
	else if (operation == DETACH)
		thread_error_handler(pthread_detach(*thread), operation);
	else
		er("Operation code not identified");

}
