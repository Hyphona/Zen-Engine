/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hyphona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 12:39:00 by Hyphona           #+#    #+#             */
/*   Updated: 2026/02/14 12:44:58 by Hyphona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zen_engine.h"

/**
 * Log the string msg with prefix to the console
 */
static size_t	log_to_console(const char *prefix, const char *msg)
{
	size_t	i;
	char	*s;

	if (!msg)
		s = ft_strjoin(prefix, "[No log message provided]");
	else
		s = ft_strjoin(prefix, msg);
	if (!s)
	{
		write(0, "logger -> strjoin() error", 25);
		return (0);
	}
	i = write(0, s, strlen(s));
	free(s);
	return (i);
}

/**
 * Zen Engine logging method (to console)
 *
 * @param mode info (0), warning (1), error (2)
 * @param msg The message to log
 * @returns On success, the number of bytes written
 * @returns On error, 0
 */
size_t	zen_log(size_t mode, char *msg)
{
	char	*prefix;

	prefix = "ZEN ENGINE -> Info: ";
	if (mode == 0)
		return (log_to_console(prefix, msg));
	prefix = "ZEN ENGINE -> Warning: ";
	if (mode == 1)
		return (log_to_console(prefix, msg));
	prefix = "ZEN ENGINE -> Error: ";
	if (mode == 2)
		return (log_to_console(prefix, msg));
	prefix = "ZEN ENGINE -> Warning: ";
	log_to_console(prefix, "zen_log() called with an invalid mode");
	log_to_console(prefix, "Available modes: info (0), warning (1), error (2)");
	log_to_console(prefix, "Fallback to warning (1) mode");
	return (log_to_console(prefix, msg));
}

/**
 * Same as zen_log() but for the game related stuff
 */
size_t	game_log(size_t mode, char *msg)
{
	char	*prefix;

	prefix = "GAME -> Info: ";
	if (mode == 0)
		return (log_to_console(prefix, msg));
	prefix = "GAME -> Warning: ";
	if (mode == 1)
		return (log_to_console(prefix, msg));
	prefix = "GAME -> Error: ";
	if (mode == 2)
		return (log_to_console(prefix, msg));
	prefix = "GAME -> Warning: ";
	log_to_console(prefix, "game_log() called with an invalid mode");
	log_to_console(prefix, "Available modes: info (0), warning (1), error (2)");
	log_to_console(prefix, "Fallback to warning (1) mode");
	return (log_to_console(prefix, msg));
}
