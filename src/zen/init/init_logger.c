/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_logger.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hyphona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 23:07:45 by Hyphona           #+#    #+#             */
/*   Updated: 2026/02/20 02:09:47 by Hyphona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zen/zen_engine.h"

static t_logger	*g_logger;

/**
 * Create a thread for the logger
 *
 * I believe the main thread should not wait for a log to be processed before
 * continuing
 *
 * @returns On success, 1
 * @returns On fail, 0
 */
static int	init_logger(void)
{
	int	t;

	if (g_logger)
	{
		write(0, "init_logger() Seems to be already initialized'\n", 47);
		return (1);
	}
	g_logger = malloc(sizeof(t_logger));
	if (!g_logger)
	{
		write(0, "init_logger() Failed'\n", 22);
		return (0);
	}
	pthread_mutex_init(&g_logger->mutex, NULL);
	g_logger->head = NULL;
	g_logger->stop_flag = 0;
	t = pthread_create(&g_logger->t_id, NULL, logger_worker, (void *) g_logger);
	if (t != 0)
		return (0);
	return (1);
}

/**
 * Send a stop flag to the logger thread & terminate it
 *
 * The logger will process the log queue before exiting
 */
void	terminate_logger(void)
{
	if (!g_logger)
	{
		write(0, "terminate_logger() Seems to be already terminated\n", 50);
		return ;
	}
	g_logger->stop_flag = 1;
	pthread_join(g_logger->t_id, NULL);
	pthread_mutex_destroy(&g_logger->mutex);
	free(g_logger);
}

/**
 * Get an initialized t_logger structure
 *
 * If the logger has already been called before, returns the existing structure
 * Otherwise, a new one will be initialized
 *
 * @returns On success, a pointer to a t_logger structure
 * @returns On fail, a null pointer
 */
t_logger	*get_logger(void)
{
	if (!g_logger)
	{
		if (!init_logger())
		{
			write(0, "get_logger() Failed to init the logger\n", 39);
			return (NULL);
		}
	}
	return (g_logger);
}
