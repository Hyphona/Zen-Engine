/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_logger.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hyphona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 23:24:35 by Hyphona           #+#    #+#             */
/*   Updated: 2026/02/23 17:03:49 by Hyphona          ###   ########.fr       */
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
	if (log_level > 2)
		log_w("zen_log() Unknow 'log_level' value");
	if (log_level == 0)
		return ("Game info: ");
	else if (log_level == 1)
		return ("Game warning: ");
	else if (log_level == 2)
		return ("Game error: ");
	return ("Game unknow: ");
}

/**
 * Log a message to the console / game_logs.txt
 *
 * Lazy load the logger when this function is called for the first time
 *
 * @param log_level The log level - (0) info, (1) warning, (2) error
 * @param msg The log message
 */
void	zen_log(size_t log_level, char *msg)
{
	t_logger	*logger;
	t_log_node	*node;

	if (!msg)
	{
		log_e("zen_log() Null pointer 'msg'");
		return ;
	}
	logger = get_logger(1);
	if (!logger)
	{
		write(1, "zen_log() Failed to get the logger\n", 35);
		return ;
	}
	node = create_log_node(get_log_level(log_level), msg);
	if (!node)
	{
		write(1, "zen_log() Failed to create node\n", 32);
		return ;
	}
	pthread_mutex_lock(&logger->mutex);
	add_to_log_queue(&logger->head, node);
	pthread_cond_signal(&logger->cond);
	pthread_mutex_unlock(&logger->mutex);
}
