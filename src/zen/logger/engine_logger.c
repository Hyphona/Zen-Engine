/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_logger.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hyphona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 12:39:41 by Hyphona           #+#    #+#             */
/*   Updated: 2026/02/23 17:03:07 by Hyphona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zen/zen_engine.h"

/**
 * Get a 'const char *' from the log level 'log_level'
 *
 * This method always succeed
 *
 * @param log_level The log level - (0) info, (1) warning, (2) error
 * @return The log level as 'const char *'
 */
static char	*get_log_level(size_t log_level)
{
	if (log_level == 0)
		return ("Engine info: ");
	else if (log_level == 1)
		return ("Engine warning: ");
	else if (log_level == 2)
		return ("Engine error: ");
	return ("Engine unknow: ");
}

/**
 * Add a node to the log queue & send a wake up signal to the logger thread
 *
 * @param log_level The log level - (0) info, (1) warning, (2) error
 * @param msg The log message
 */
static void	engine_logger(size_t log_level, char *msg)
{
	t_logger	*logger;
	t_log_node	*node;

	if (!msg)
	{
		log_e("engine_logger() Null pointer 'msg'");
		return ;
	}
	logger = get_logger(1);
	if (!logger)
	{
		write(1, "engine_logger() Failed to get the logger\n", 41);
		return ;
	}
	node = create_log_node(get_log_level(log_level), msg);
	if (!node)
	{
		write(1, "engine_logger() Failed to create node\n", 38);
		return ;
	}
	pthread_mutex_lock(&logger->mutex);
	add_to_log_queue(&logger->head, node);
	pthread_cond_signal(&logger->cond);
	pthread_mutex_unlock(&logger->mutex);
}

/**
 * Log an engine information
 *
 * @param str The log message
 */
void	log_i(char *msg)
{
	if (!msg)
	{
		log_e("log_i() Null pointer 'msg'");
		return ;
	}
	engine_logger(0, msg);
}

/**
 * Log an engine warning
 *
 * @param str The log message
 */
void	log_w(char *msg)
{
	if (!msg)
	{
		log_e("log_w() Null pointer 'str'");
		return ;
	}
	engine_logger(1, msg);
}

/**
 * Log an engine error
 *
 * @param str The log message
 */
void	log_e(char *msg)
{
	if (!msg)
	{
		log_e("log_e() Null pointer 'str'");
		return ;
	}
	engine_logger(2, msg);
}
