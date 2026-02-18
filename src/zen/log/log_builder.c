/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_builder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hyphona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 23:57:45 by Hyphona           #+#    #+#             */
/*   Updated: 2026/02/18 02:31:00 by Hyphona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zen/zen_engine.h"

/**
 * Get the prefix to use when building the log message
 *
 * @param is_game If the request comes from the game or the engine
 * 	- (0) Request from the engine
 *	- (1) Request from the game
 * @return The log prefix
 */
static const char	*get_log_name(size_t is_game)
{
	if (is_game == 0)
		return ("\nZEN ENGINE");
	if (is_game == 1)
		return ("\nGAME");
	zen_log(0, 1, "get_log_name(): Unknow 'is_game' value");
	return ("\n???");
}

/**
 * Get the log level to use when building the log message
 *
 * @param log_level The log level
 *	- (0) INFO
 *	- (1) WARNING
 *	- (2) ERROR
 * @return The log level prefix
 */
static const char	*get_log_level(size_t log_level)
{
	if (log_level == 0)
		return (" - INFO - ");
	if (log_level == 1)
		return (" - WARNING - ");
	if (log_level == 2)
		return (" - ERROR - ");
	zen_log(0, 1, "get_log_level(): Unknow 'log_level' value");
	return (" - ??? - ");
}

/**
 * Build the log line (prefix + log level + log message)
 *
 * @param is_game If the request comes from the game or the engine
 * @param log_level The log level
 * @param msg The log message
 * @return A malloced string (the log line)
 */
char	*build_log_line(size_t is_game, size_t log_level, const char *msg)
{
	char		*prefix;
	char		*log_line;

	if (!msg)
	{
		zen_log(0, 2, "build_log_line(): Empty pointer 'msg'");
		return (NULL);
	}
	prefix = ft_strjoin(get_log_name(is_game), get_log_level(log_level));
	if (!prefix)
	{
		zen_log(0, 2, "build_log_line(): Couldn't create the log prefix");
		return (NULL);
	}
	log_line = ft_strjoin(prefix, msg);
	free(prefix);
	if (!log_line)
	{
		zen_log(0, 2, "build_log_line(): Couldn't create the log message");
		return (NULL);
	}
	return (log_line);
}
