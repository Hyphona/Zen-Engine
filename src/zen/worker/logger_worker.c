/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger_worker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hyphona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 23:18:06 by Hyphona           #+#    #+#             */
/*   Updated: 2026/02/19 21:09:42 by Hyphona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zen/zen_engine.h"

/**
 * Write a log message to the provided file descriptor
 *
 * @param fd The file descriptor
 * @param log_line The log message
 */
static void	write_log(int fd, const char *log_line)
{
	if (fd < 0)
		return ;
	if (!log_line)
		return ;
	write(fd, log_line, strlen(log_line));
}

/**
 * The method that actually listen to the log queue
 *
 * Check for a stop flag, but only stop when the queue is cleared
 */
void	*logger_worker(void *arg)
{
	t_logger	*logger;
	t_log_node	*current;
	int			fd;

	logger = (t_logger *) arg;
	fd = open("./zen_engine_logs.txt", O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (fd < 0)
		return ((void *) write(0, "logger_worker() Failed\n", 23));
	while (1)
	{
		if (logger->head)
		{
			pthread_mutex_lock(&logger->mutex);
			current = (t_log_node *) logger->head;
			write_log(fd, current->msg);
			write_log(0, current->msg);
			remove_from_log_queue(&logger->head);
			pthread_mutex_unlock(&logger->mutex);
		}
		if (logger->stop_flag == 1 && !logger->head)
			break ;
		usleep(1000);
	}
	close(fd);
	return (NULL);
}
