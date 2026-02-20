/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_logger.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hyphona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 23:24:35 by Hyphona           #+#    #+#             */
/*   Updated: 2026/02/20 13:42:24 by Hyphona          ###   ########.fr       */
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
static const char	*get_log_level(size_t log_level)
{
	if (log_level == 0)
		return ("Game info: ");
	if (log_level == 1)
		return ("Game warning: ");
	if (log_level == 2)
		return ("Game error: ");
	return ("Game unknow: ");
}

/**
 * Build the log line (append the log level & the log message)
 *
 * @param log_level The log level - (0) info, (1) warning, (2) error
 * @param msg The log message
 * @returns On success, a pointer to a string
 * @returns On fail, a null pointer
 */
static char	*build_log_line(size_t log_level, const char *msg)
{
	char		*log_line;

	if (!msg)
	{
		log_e("build_log_line() Null pointer 'msg'");
		return (NULL);
	}
	log_line = ft_strjoin(get_log_level(log_level), msg);
	if (!log_line)
	{
		log_e("build_log_line() Failed");
		return (NULL);
	}
	return (log_line);
}

/**
 * Log a message to the console / game_logs.txt
 *
 * When calling this method for the first time, a new thread will be created
 * For each following call, the log message will be stored in a queue waiting
 * for the thread to process it
 *
 * @param log_level The log level - (0) info, (1) warning, (2) error
 * @param msg The log message
 */
void	zen_log(size_t log_level, const char *msg)
{
	char		*log_line;
	t_logger	*logger;

	if (!msg)
	{
		log_e("zen_log() Null pointer 'msg'");
		return ;
	}
	if (log_level > 2)
		log_w("zen_log() Unknow 'log_level' value");
	log_line = build_log_line(log_level, msg);
	if (!log_line)
	{
		log_e("zen_log() Failed to build the log line");
		return ;
	}
	logger = get_logger();
	if (!logger)
	{
		log_e("zen_log() Failed to get the logger");
		return ;
	}
	pthread_mutex_lock(&logger->mutex);
	add_to_log_queue(&logger->head, create_log_node(log_line));
	pthread_mutex_unlock(&logger->mutex);
}
