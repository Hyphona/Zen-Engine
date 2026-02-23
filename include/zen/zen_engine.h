/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zen_engine.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hyphona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 12:41:14 by Hyphona           #+#    #+#             */
/*   Updated: 2026/02/23 12:46:14 by Hyphona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZEN_ENGINE_H
# define ZEN_ENGINE_H

# include "zen/zen.h"
# include <pthread.h>
# include <string.h>

typedef struct log_node_s
{
	char				*lvl;
	char				*msg;
	struct log_node_s	*next;
}						t_log_node;

typedef struct logger_s
{
	pthread_mutex_t		mutex;
	pthread_t			t_id;
	pthread_cond_t		cond;
	struct log_node_s	*head;
	_Atomic int			stop_flag;
}						t_logger;

void		log_i(char *str);
void		log_w(char *str);
void		log_e(char *str);
void		terminate_logger(void);
t_logger	*get_logger(int init);
void		*logger_worker(void *arg);
t_log_node	*create_log_node(char *lvl, char *msg);
void		add_to_log_queue(t_log_node **head, t_log_node *new);
t_log_node	*pop_from_log_queue(t_log_node **head);

#endif
