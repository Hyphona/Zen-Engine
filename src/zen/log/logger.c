/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hyphona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 23:24:35 by Hyphona           #+#    #+#             */
/*   Updated: 2026/02/18 02:31:15 by Hyphona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zen/zen_engine.h"

/**
 * Write a log message to the provided file descriptor
 *
 * @param fd The file descriptor
 * @param log_line The log message
 * @return The number of bytes written
 */
static size_t	write_log(int fd, const char *log_line)
{
	size_t	i;

	if (fd < 0)
	{
		zen_log(0, 2, "write_log(): Invalid file descriptor provided");
		return (0);
	}
	if (!log_line)
	{
		zen_log(0, 2, "write_log(): Empty pointer 'log_line'");
		return (0);
	}
	i = write(fd, log_line, strlen(log_line));
	return (i);
}

/**
 * Write a log message to the console
 *
 * @param log_line The log message
 * @return The number of bytes written
 */
static size_t	log_to_console(const char *log_line)
{
	if (!log_line)
	{
		zen_log(0, 2, "log_to_console(): Empty pointer 'log_line'");
		return (0);
	}
	return (write_log(0, log_line));
}

/**
 * Write a log message to zen_engine_logs.txt
 *
 * @param log_line The log message
 * @return The number of bytes written
 */
static size_t	log_to_file(const char *log_line)
{
	size_t	i;
	int		fd;

	if (!log_line)
	{
		zen_log(0, 2, "log_to_file(): Empty pointer 'log_line'");
		return (0);
	}
	fd = open("./zen_engine_logs.txt", O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (fd < 0)
	{
		zen_log(0, 2, "log_to_file(): Unable to open ./zen_engine_logs.txt");
		return (0);
	}
	i = write_log(fd, log_line);
	close(fd);
	return (i);
}

/**
 * Log a message to the console / zen_engine_logs.txt
 *
 * @param is_game If the log message comes from the game
 * @param log_level The log level - (0) INFO - (1) WARNING - (2) ERROR
 * @param log_msg The log message
 * @return The number of bytes written
 */
size_t	zen_log(size_t is_game, size_t log_level, const char *log_msg)
{
	char	*log_line;
	size_t	i;

	if (!log_msg)
	{
		zen_log(0, 2, "zen_log(): Empty 'log_msg' pointer");
		return (0);
	}
	log_line = build_log_line(is_game, log_level, log_msg);
	if (!log_line)
	{
		zen_log(0, 2, "zen_log(): Couldn't build the log line");
		return (0);
	}
	i = log_to_file(log_line);
	i = i + log_to_console(log_line);
	free(log_line);
	return (i);
}
