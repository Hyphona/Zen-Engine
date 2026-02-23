/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_logger.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hyphona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 23:07:45 by Hyphona           #+#    #+#             */
/*   Updated: 2026/02/23 12:49:06 by Hyphona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zen/zen_engine.h"

/**
 * Create a thread for the logger
 *
 * I believe the main thread should not wait for a log to be processed before
 * continuing
 *
 * @param logger A pointer to a 't_logger' struct
 * @returns On success, a pointer to a 't_logger' struct
 * @returns On fail, a null pointer
 */
static t_logger	*init_logger(t_logger *logger)
{
	int	t;

	if (logger)
	{
		log_w("init_logger() Logger seems to be already initialized");
		return (NULL);
	}
	logger = malloc(sizeof(t_logger));
	if (!logger)
	{
		write(1, "init_logger() Failed to allocate memory\n", 40);
		return (NULL);
	}
	pthread_mutex_init(&logger->mutex, NULL);
	pthread_cond_init(&logger->cond, NULL);
	logger->head = NULL;
	logger->stop_flag = 0;
	t = pthread_create(&logger->t_id, NULL, logger_worker, (void *) logger);
	if (t != 0)
	{
		write(1, "init_logger() Failed to create the thread\n", 42);
		return (NULL);
	}
	return (logger);
}

/**
 * Get the logger
 *
 * Lazy load the logger thread when this function is called for the first time
 * (Except if the init parameter is set to 0)
 *
 * @param init If this function should init the logger thread or not
 * @returns On success, a pointer to a t_logger structure
 * @returns On fail, a null pointer
 */
t_logger	*get_logger(int init)
{
	static t_logger	*logger = NULL;

	if (!init)
		return (logger);
	if (!logger)
	{
		logger = init_logger(logger);
		if (!logger)
		{
			write(1, "get_logger() Failed to init the logger\n", 39);
			return (NULL);
		}
	}
	return (logger);
}
