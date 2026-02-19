/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hyphona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 23:24:35 by Hyphona           #+#    #+#             */
/*   Updated: 2026/02/19 17:51:24 by Hyphona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zen/zen_engine.h"

/**
 * Log a message to the console / zen_engine_logs.txt
 *
 * @param log_level The log level - (0) INFO - (1) WARNING - (2) ERROR
 * @param msg The log message
 */
void	zen_log(size_t log_level, const char *msg)
{
	char		*log_line;
	t_logger	*logger;

	if (!msg)
	{
		zen_log(2, "zen_log() Null pointer 'msg'");
		return ;
	}
	log_line = build_log_line(log_level, msg);
	if (!log_line)
	{
		zen_log(2, "zen_log() Couldn't build the log line");
		return ;
	}
	logger = get_logger();
	if (!logger)
		return ;
	add_to_log_queue(&logger->head, create_log_node(log_line));
}
