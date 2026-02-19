/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_builder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hyphona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 23:57:45 by Hyphona           #+#    #+#             */
/*   Updated: 2026/02/19 17:50:02 by Hyphona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zen/zen_engine.h"

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
		return ("INFO - ");
	if (log_level == 1)
		return ("WARNING - ");
	if (log_level == 2)
		return ("ERROR - ");
	zen_log(1, "get_log_level(): Unknow 'log_level' value");
	return ("??? - ");
}

/**
 * Build the log line (prefix + log level + log message)
 *
 * @param log_level The log level
 * @param msg The log message
 * @return A malloced string (the log line)
 */
char	*build_log_line(size_t log_level, const char *msg)
{
	char		*prefix;
	char		*log_line;

	if (!msg)
	{
		zen_log(2, "build_log_line() Null pointer 'msg'");
		return (NULL);
	}
	prefix = ft_strjoin("\nZen Engine:", get_log_level(log_level));
	if (!prefix)
	{
		zen_log(2, "build_log_line() Couldn't create the log prefix");
		return (NULL);
	}
	log_line = ft_strjoin(prefix, msg);
	free(prefix);
	if (!log_line)
	{
		zen_log(2, "build_log_line() Couldn't create the log message");
		return (NULL);
	}
	return (log_line);
}
