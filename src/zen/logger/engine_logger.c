/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_logger.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hyphona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 12:39:41 by Hyphona           #+#    #+#             */
/*   Updated: 2026/02/20 13:41:40 by Hyphona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zen/zen_engine.h"

/**
 * The method that actually write the engine logs
 *
 * It first check if the user initialized the 't_logger' thread to avoid
 * initializing it by calling 'get_logger()'
 *
 * Mutex will be used if 't_logger' has been initialized
 *
 * @param lvl The log level
 * @param str The log message
 */
static void	write_engine_log(const char *lvl, const char *str)
{
	t_logger	*game_logger;

	game_logger = NULL;
	if (logger_exists())
	{
		game_logger = get_logger();
		pthread_mutex_lock(&game_logger->mutex);
	}
	if (!lvl)
		write(0, "Engine unknow: ", 15);
	else
		write(0, lvl, strlen(lvl));
	if (!str)
		write(0, "(error) write_engine_log() Null pointer 'str'", 45);
	else
		write(0, str, strlen(str));
	write(0, "\n", 1);
	if (game_logger)
		pthread_mutex_unlock(&game_logger->mutex);
}

/**
 * Log an engine information
 *
 * @param str The log message
 */
void	log_i(const char *str)
{
	if (!str)
	{
		write(0, "log_i() Null pointer 'str'\n", 27);
		return ;
	}
	write_engine_log("Engine info: ", str);
}

/**
 * Log an engine warning
 *
 * @param str The log message
 */
void	log_w(const char *str)
{
	if (!str)
	{
		write(0, "log_w() Null pointer 'str'\n", 27);
		return ;
	}
	write_engine_log("Engine warning: ", str);
}

/**
 * Log an engine error
 *
 * @param str The log message
 */
void	log_e(const char *str)
{
	if (!str)
	{
		write(0, "log_e() Null pointer 'str'\n", 27);
		return ;
	}
	write_engine_log("Engine error: ", str);
}
