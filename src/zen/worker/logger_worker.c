/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger_worker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hyphona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 23:18:06 by Hyphona           #+#    #+#             */
/*   Updated: 2026/02/20 19:21:01 by Hyphona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zen/zen_engine.h"

/**
 * Write a log message to the provided file descriptor
 *
 * This method won't 'close()' the file descriptor
 *
 * @param fd The file descriptor
 * @param lvl The log level as 'char *'
 * @param msg The log message
 */
static void	write_log(int fd, const char *lvl, const char *msg)
{
	ssize_t	w_lvl;
	ssize_t	w_msg;

	if (!fd || !lvl || !msg)
	{
		if (!fd)
			log_e("write_log() Invalid file descriptor 'fd'");
		if (!lvl)
			log_e("write_log() Null pointer 'lvl'");
		if (!msg)
			log_e("write_log() Null pointer 'msg'");
		return ;
	}
	w_lvl = write(fd, lvl, strlen(lvl));
	if (w_lvl > 0)
		w_msg = write(fd, msg, strlen(msg));
	if (w_lvl < 0 || w_msg < 0)
	{
		if (w_lvl < 0)
			log_e("write_log() Couldn't write 'lvl'");
		if (w_msg < 0)
			log_e("write_log() Couldn't write 'msg'");
		return ;
	}
	write(fd, "\n", 1);
}

/**
 * Open the 'game_logs.txt' file
 *
 * @returns On success, return a file descriptor (int > 0)
 * @returns On fail, return 0
 */
static int	get_log_file(void)
{
	int	fd;

	fd = open("./game_logs.txt", O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (fd < 0)
	{
		log_w("get_log_file() Failed to open 'game_logs.txt'");
		log_w("get_log_file() Logs will only be written to console");
		return (0);
	}
	return (fd);
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
	fd = get_log_file();
	while (1)
	{
		if (logger->head)
		{
			pthread_mutex_lock(&logger->mutex);
			current = (t_log_node *) logger->head;
			if (fd)
				write_log(fd, current->lvl, current->msg);
			write_log(1, current->lvl, current->msg);
			remove_from_log_queue(&logger->head);
			pthread_mutex_unlock(&logger->mutex);
		}
		if (logger->stop_flag == 1 && !logger->head)
			break ;
		usleep(10000);
	}
	if (fd)
		close(fd);
	return (NULL);
}
