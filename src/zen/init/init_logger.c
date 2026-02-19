/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_logger.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hyphona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 23:07:45 by Hyphona           #+#    #+#             */
/*   Updated: 2026/02/20 00:41:02 by Hyphona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zen/zen_engine.h"

static t_logger	*g_logger;

/**
 * Init a thread for the logger
 *
 * The logger init automatically the first time zen_log() is called
 *
 * @return 1 on success, 0 if it fails
 */
static int	init_logger(void)
{
	int	t;

	if (g_logger)
	{
		write(0, "init_logger() Seems to be already initialized'\n", 47);
		return (0);
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
 * Wait for the logger thread and terminate it
 */
void	terminate_logger(void)
{
	if (!g_logger)
		return ;
	g_logger->stop_flag = 1;
	pthread_join(g_logger->t_id, NULL);
	pthread_mutex_destroy(&g_logger->mutex);
	free(g_logger);
}

/**
 * Get the initialized logger or init one if no one exists
 *
 * @return a t_logger object
 */
t_logger	*get_logger(void)
{
	if (!g_logger)
	{
		if (!init_logger())
		{
			write(0, "get_logger() Failed to init logger\n", 35);
			return (NULL);
		}
	}
	return (g_logger);
}
