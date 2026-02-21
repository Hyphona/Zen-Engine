/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_logger.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hyphona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 23:07:45 by Hyphona           #+#    #+#             */
/*   Updated: 2026/02/21 15:36:22 by Hyphona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zen/zen_engine.h"

/**
 * Create a thread for the logger
 *
 * I believe the main thread should not wait for a log to be processed before
 * continuing
 *
 * @returns On success, 1
 * @returns On fail, 0
 */
static int	init_logger(t_logger *logger)
{
	int	t;

	if (logger)
	{
		log_w("init_logger() Logger seems to be already initialized");
		return (1);
	}
	logger = malloc(sizeof(t_logger));
	if (!logger)
	{
		log_e("init_logger() Failed to allocate memory");
		return (0);
	}
	pthread_mutex_init(&logger->mutex, NULL);
	logger->head = NULL;
	logger->stop_flag = 0;
	t = pthread_create(&logger->t_id, NULL, logger_worker, (void *) logger);
	if (t != 0)
	{
		log_e("init_logger() Failed to create the thread");
		return (0);
	}
	return (1);
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
	if (!logger && !init_logger(logger))
	{
		log_e("get_logger() Failed to init the logger");
		return (NULL);
	}
	return (logger);
}

/**
 * Send a stop flag to the logger thread & terminate it
 *
 * The logger will process the log queue before exiting
 */
void	terminate_logger(void)
{
	t_logger	*logger;

	logger = get_logger(0);
	if (!logger)
	{
		log_w("terminate_logger() Logger seems to be already terminated");
		return ;
	}
	logger->stop_flag = 1;
	pthread_join(logger->t_id, NULL);
	pthread_mutex_destroy(&logger->mutex);
	free(logger);
}
