/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hyphona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 11:08:55 by Hyphona           #+#    #+#             */
/*   Updated: 2026/02/13 15:40:16 by Hyphona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/**
 * Log the string msg with prefix to the console
 */
static ssize_t	log_to_console(char *prefix, char *msg)
{
	ssize_t	i;
	char	*s;

	if (!msg)
		s = ft_strjoin(prefix, "[No log message available]");
	else
		s = ft_strjoin(prefix, msg);
	if (!s)
	{
		write(0, "logger -> ft_strjoin() error", 28);
		return (-1);
	}
	i = write(0, s, ft_strlen(s));
	free(s);
	return (i);
}

/**
 * Zenspire engine logging method (to console)
 *
 * Behave like the write() method
 *
 * Take the mode and the message to output as arguments
 * Available modes:
 *	- info 		(0)
 *	- warning 	(1)
 *	- error 	(2)
 * 
 * On success, the number of bytes written is returned
 * On error, -1 is returned
 */
ssize_t	zen_log(size_t mode, char *msg)
{
	char	*prefix;

	prefix = "ZENSPIRE ENGINE -> Info: ";
	if (mode == 0)
		return (log_to_console(prefix, msg));
	prefix = "ZENSPIRE ENGINE -> Warning: ";
	if (mod == 1)
		return (log_to_console(prefix, msg));
	prefix = "ZENSPIRE ENGINE -> Error: ";
	if (mode == 2)
		return (log_to_console(prefix, msg));
	prefix = "ZENSPIRE ENGINE -> Warning: ";
	log_to_console(prefix, "zen_log() called with an invalid mode");
	log_to_console(prefix, "Available modes: info (0), warning (1), error (2)");
	log_to_console(prefix, "Fallback to warning (1) mode");
	return (log_to_console(prefix, msg));
}

/**
 * Same as zen_log() but for the game related stuff
 */
ssize_t	game_log(size_t mode, char *msg)
{
	char	*prefix;

	prefix = "GAME -> Info: ";
	if (mode == 0)
		return (log_to_console(prefix, msg));
	prefix = "GAME -> Warning: ";
	if (mod == 1)
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
