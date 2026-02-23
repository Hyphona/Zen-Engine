/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate_logger.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hyphona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 00:59:43 by Hyphona           #+#    #+#             */
/*   Updated: 2026/02/23 13:28:03 by Hyphona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zen/zen_engine.h"

/**
 * Set the 'stop_flag' to 1 & terminate the logger thread
 *
 * The logger will process the log queue before exiting
 */
void	terminate_logger(void)
{
	t_logger	*logger;

	logger = get_logger(0);
	if (!logger)
	{
		write(1, "terminate_logger() Logger seems already terminated\n", 51);
		return ;
	}
	logger->stop_flag = 1;
	pthread_cond_signal(&logger->cond);
	pthread_join(logger->t_id, NULL);
	pthread_mutex_destroy(&logger->mutex);
	pthread_cond_destroy(&logger->cond);
	free(logger);
}
