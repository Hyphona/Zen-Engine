/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger_worker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hyphona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 23:18:06 by Hyphona           #+#    #+#             */
/*   Updated: 2026/02/23 17:31:14 by Hyphona          ###   ########.fr       */
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
 * Process the log node
 *
 * This function mainly exists because otherwise the logger_worker()
 * function would have been more than 25 lines long (because of the
 * check that make sure 'node' isn't null)
 *
 * Anyway, in the end I find it better for code readability to
 * seperate the processing of the node & the thread loop
 *
 * @param fd The file descriptor
 * @param node The 't_log_node' struct to process
 */
static void	process_node(int fd, t_log_node *node)
{
	if (!node)
	{
		log_e("process_node() Null pointer 'node'");
		return ;
	}
	if (fd)
		write_log(fd, node->lvl, node->msg);
	write_log(1, node->lvl, node->msg);
	free(node);
}

/**
 * Keeps the logger thread alive & listen for new logs entries
 *
 * The thread sleeps until a wake up signal is sent (avoid busy waiting)
 * Check for a stop flag, but only stop when the queue is cleared
 */
void	*logger_worker(void *arg)
{
	t_logger	*logger;
	t_log_node	*node;
	int			fd;

	logger = (t_logger *) arg;
	fd = get_log_file();
	while (1)
	{
		pthread_mutex_lock(&logger->mutex);
		while (!logger->head && !logger->stop_flag)
			pthread_cond_wait(&logger->cond, &logger->mutex);
		if (logger->stop_flag && !logger->head)
			break ;
		node = pop_from_log_queue(&logger->head);
		pthread_mutex_unlock(&logger->mutex);
		process_node(fd, node);
	}
	if (fd)
		close(fd);
	return (NULL);
}
