/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_logger.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hyphona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 12:39:41 by Hyphona           #+#    #+#             */
/*   Updated: 2026/02/21 15:30:14 by Hyphona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zen/zen_engine.h"

/**
 * Log an engine information
 *
 * @param str The log message
 */
void	log_i(char *msg)
{
	t_logger	*logger;

	if (!msg)
	{
		write(1, "log_i() Null pointer 'msg'\n", 27);
		return ;
	}
	logger = get_logger(1);
	pthread_mutex_lock(&logger->mutex);
	add_to_log_queue(&logger->head, create_log_node("Engine info: ", msg));
	pthread_mutex_unlock(&logger->mutex);
}

/**
 * Log an engine warning
 *
 * @param str The log message
 */
void	log_w(char *msg)
{
	t_logger	*logger;

	if (!msg)
	{
		write(1, "log_w() Null pointer 'str'\n", 27);
		return ;
	}
	logger = get_logger(1);
	pthread_mutex_lock(&logger->mutex);
	add_to_log_queue(&logger->head, create_log_node("Engine warning: ", msg));
	pthread_mutex_unlock(&logger->mutex);
}

/**
 * Log an engine error
 *
 * @param str The log message
 */
void	log_e(char *msg)
{
	t_logger	*logger;

	if (!msg)
	{
		write(1, "log_e() Null pointer 'str'\n", 27);
		return ;
	}
	logger = get_logger(1);
	pthread_mutex_lock(&logger->mutex);
	add_to_log_queue(&logger->head, create_log_node("Engine error: ", msg));
	pthread_mutex_unlock(&logger->mutex);
}
