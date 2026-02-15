/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hyphona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 12:39:00 by Hyphona           #+#    #+#             */
/*   Updated: 2026/02/15 13:15:49 by Hyphona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zen_engine.h"

/**
 * Log the string msg with prefix to the console
 */
static size_t	to_console(const char *prefix, const char *msg)
{
	size_t	i;
	char	*s;

	if (!msg)
		s = ft_strjoin(prefix, "[No log message provided]\n");
	else
		s = ft_strjoin(prefix, msg);
	if (!s)
	{
		write(0, "logger.c -> ft_strjoin() error\n", 31);
		return (0);
	}
	i = write(0, s, strlen(s));
	free(s);
	return (i);
}

/**
 * Zen Engine logging method
 *
 * @param mode info (0), warning (1), error (2)
 * @param msg The message to log
 * @returns On success, the number of bytes written
 * @returns On error, 0
 */
size_t	zen_log(size_t mode, char *msg)
{
	if (mode == 0)
		return (to_console("ZEN ENGINE->I ", msg));
	else if (mode == 1)
		return (to_console("ZEN ENGINE->W ", msg));
	else if (mode == 2)
		return (to_console("ZEN ENGINE->E ", msg));
	to_console("ZEN ENGINE->W ", "zen_log() - Unknow mode\n");
	to_console("ZEN ENGINE->W ", "Modes: info (0), warning (1), error (2)\n");
	to_console("ZEN ENGINE->W ", "Fallback to warning (1)\n");
	return (to_console("ZEN ENGINE->W ", msg));
}

/**
 * Game logging method
 *
 * @param mode info (0), warning (1), error (2)
 * @param msg The message to log
 * @returns On success, the number of bytes written
 * @returns On error, 0
 */
size_t	game_log(size_t mode, char *msg)
{
	if (mode == 0)
		return (to_console("GAME->I: ", msg));
	else if (mode == 1)
		return (to_console("GAME->W: ", msg));
	else if (mode == 2)
		return (to_console("GAME->E: ", msg));
	to_console("GAME->W: ", "game_log() - Unknow mode\n");
	to_console("GAME->W: ", "Modes: info (0), warning (1), error (2)\n");
	to_console("GAME->W: ", "Fallback to warning (1)\n");
	return (to_console("GAME->W: ", msg));
}
